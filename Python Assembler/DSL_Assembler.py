#!/usr/bin/python
"""
Vincent Steil
s1008380
Digital Systems Laboratory Assembler
DSL_Assembler.py
Pydoc:
pydoc -w DSL_Assembler


This is an assembler and linker for the ISR of the processor used in the Digital Systems Laboratory
It takes a text file in pseudo MIPS and turns it into a hex file

Instruction Format:
target_mem      is hex
TR, SR          are A-B (or later further registers)
function        is the function name

lw TR1 target_mem
sw TR1 target_mem
add SR1 SR2 TR1
sub SR1 SR2 TR1
mul SR1 SR2 TR1
or  SR1 SR2 TR1
xor SR1 SR2 TR1
and SR1 SR2 TR1
sll SR1 TR1
srl SR1 TR1
inc SR1 TR1
dec SR1 TR1
beq SR1 SR2 function
bgt SR1 SR2 function
blt SR1 SR2 function
idle
return
deref SR1
goto function
jr  function
li TR1 Imm


Peripheral ISR names:
Mouse_ISR
Timer_ISR

Initialisation name (first function to call): 
Processor_Init

Usage (command line):
pypy DSL_Assembler.py -i Mouse_Demo_PseudoMips.txt -o Mouse_Assembled.txt
"""

from __future__ import print_function
import sys, getopt


class Function:
    """
    docstring for Function
    Function datastructure
    Contains multiple Instruction
    Has a custom length() function to account for lw,sw etc taking two lines of memory
    """

    functions = {}
    current_function = ""

    def __init__(self, name):
        self.name = name
        self.ROM_location = 0
        self.instructions = []


    def __len__(self):
        count = 0

        for instr in self.instructions:
            count += len(instr)

        return count
  

class Instruction:
    """
    docstring for Instruction
    Instruction datastructure
    """
    def __init__(self, instruction, source_register1 = None, source_register2 = None, memory_addr = None, function_target = None, target_register = None, immediate = None):
        self.source_register1   = source_register1
        self.source_register2   = source_register2
        self.memory_addr        = memory_addr
        self.function_target    = function_target
        self.target_register    = target_register
        self.immediate          = immediate
        self.instruction        = instruction
        self.instruction_ROM    = ""
        # automatic instruction decode on creation
        # function calls are resolved later once all data is read in
        if instruction == "lw":
            # A = 0, B = 1
            self.instruction_ROM = format(ord(target_register) - 65, '02X')

        elif instruction == "sw":
            self.instruction_ROM = format(ord(target_register) - 63, '02X')

        elif instruction == "add":
            self.instruction_ROM = "0" + str(ord(target_register) - 61)

        elif instruction == "sub":
            self.instruction_ROM = "1" + str(ord(target_register) - 61)

        elif instruction == "or":
            self.instruction_ROM = "C" + str(ord(target_register) - 61)

        elif instruction == "and":
            self.instruction_ROM = "D" + str(ord(target_register) - 61)

        elif instruction == "xor":
            self.instruction_ROM = "E" + str(ord(target_register) - 61)

        elif instruction == "mul":
            self.instruction_ROM = "2" + str(ord(target_register) - 61)

        elif instruction == "sll":
            self.instruction_ROM = "3" + str(ord(target_register) - 61)

        elif instruction == "srl":
            self.instruction_ROM = "4" + str(ord(target_register) - 61)

        elif instruction == "inc":
            self.instruction_ROM = str(ord(source_register1) - 60) + str(ord(target_register) - 61)

        elif instruction == "dec":
            self.instruction_ROM = str(ord(source_register1) - 58) + str(ord(target_register) - 61)

        elif instruction == "beq":
            self.instruction_ROM = "96"

        elif instruction == "bgt":
            self.instruction_ROM = "A6"

        elif instruction == "blt":
            self.instruction_ROM = "B6"

        elif instruction == "idle":
            self.instruction_ROM = "08"

        elif instruction == "return":
            self.instruction_ROM = "0A"

        elif instruction == "deref":
            self.instruction_ROM = "0" + str(chr(ord(source_register1) + 1))

        elif instruction == "jr":
            self.instruction_ROM = "09"

        elif instruction == "goto":
            self.instruction_ROM = "07"

        elif instruction == "li":
            self.instruction_ROM = format(ord(target_register) - 51, '02X')


    def __len__(self):
        if self.instruction in ["lw","sw","beq","bgt","blt","goto","jr","li"]:
            return 2
        else:
            return 1




def set_IO(argv):
    """
    sets the IO strings from command line arguments
    """
    inputfile = ''
    outputfile = ''
    try:
        opts, args = getopt.getopt(argv,"hi:o:",["ifile=","ofile="])
    except getopt.GetoptError:
        print('DSL_Assembler.py -i <inputfile> -o <outputfile>')
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print('DSL_Assembler.py -i <inputfile> -o <outputfile>')
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-o", "--ofile"):
            outputfile = arg
    print ('Input file is "', inputfile)
    print ('Output file is "', outputfile)
    return [inputfile, outputfile]


def read_data(infile):
    """
    read inputfile into local datastructures
    """
    with open(infile, 'r') as f:
        print("Starting to read in data")
        for line in f:
            line = line.split()
            # skip empty lines
            if len(line) > 0:
                if line[0] not in ["lw","sw","add","sub","mul","or","xor","and","sll","srl","inc","dec","beq","bgt","blt","idle","return","deref","goto", "jr","li"]:
                    # assume we are starting a new function
                    Function.functions[line[0]] = Function(line[0])
                    Function.current_function = line[0]

                elif line[0] in ["lw","sw"]:
                    assert Function.current_function in Function.functions
                    Function.functions[Function.current_function].instructions.append(Instruction(instruction = line[0], target_register = line[1], memory_addr = line[2]))

                elif line[0] in ["add","sub","mul","or","and","xor"]:
                    assert Function.current_function in Function.functions
                    Function.functions[Function.current_function].instructions.append(Instruction(instruction = line[0], source_register1 = line[1], source_register2 = line[2], target_register = line[3]))

                elif line[0] in ["sll","srl","inc","dec"]:
                    assert Function.current_function in Function.functions
                    Function.functions[Function.current_function].instructions.append(Instruction(instruction = line[0], source_register1 = line[1], target_register = line[2]))

                elif line[0] in ["beq","bgt","blt"]:
                    assert Function.current_function in Function.functions
                    Function.functions[Function.current_function].instructions.append(Instruction(instruction = line[0], source_register1 = line[1], source_register2 = line[2], function_target = line[3]))

                elif line[0] in ["idle","return"]:
                    assert Function.current_function in Function.functions
                    Function.functions[Function.current_function].instructions.append(Instruction(instruction = line[0]))

                elif line[0] in ["deref"]:
                    assert Function.current_function in Function.functions
                    Function.functions[Function.current_function].instructions.append(Instruction(instruction = line[0], source_register1 = line[1]))  

                elif line[0] in ["goto","jr"]:
                    assert Function.current_function in Function.functions
                    Function.functions[Function.current_function].instructions.append(Instruction(instruction = line[0], function_target = line[1]))

                elif line[0] in ["li"]:
                    assert Function.current_function in Function.functions
                    Function.functions[Function.current_function].instructions.append(Instruction(instruction = line[0], target_register = line[1], immediate = line[2]))

    print("Finished reading in data")


ROM_Size = 256
ROM = []


def link():
    """
    link functions and map them to the ROM array after assembling
    """
    print("Start linking")
    # init array with zeroes
    for x in xrange(0, ROM_Size):
        ROM.append("00")
    
    # Program Counter
    PC = 0

    # process the functions that are guaranteed to turn up (since I mandate it for running the assembler)

    fns = Function.functions
    prog_size = 0

    assert "Processor_Init" in fns
    prog_size = len(fns["Processor_Init"])
    assert prog_size + PC < 0xFE

    fns["Processor_Init"].ROM_location = PC
    PC += prog_size

    assert "Mouse_ISR" in fns
    prog_size = len(fns["Mouse_ISR"])
    assert prog_size + PC < 0xFE


    ROM[0xFF] = format(PC, '02X')

    fns["Mouse_ISR"].ROM_location = PC
    PC += prog_size
   
    assert "Timer_ISR" in fns
    prog_size = len(fns["Timer_ISR"])
    assert prog_size + PC < 0xFE



    ROM[0xFE] = format(PC, '02X')

    fns["Timer_ISR"].ROM_location = PC
    PC += prog_size

    # now with the three mandatory functions taken care of, we can add any other functions we might want
    # this loop takes care of slotting in all the functions
    for fn in fns.values():
        if fn.name not in ["Processor_Init","Mouse_ISR","Timer_ISR"]:

            prog_size = len(fn.instructions)
            assert prog_size + PC < 0xFE

            fn.ROM_location = PC
            PC += prog_size


    # this loop actually itterates through all instructions and places them correctly and resolves function_target values to hex values
    for fn in fns.values():
        PC_offset = 0
        for instr in fn.instructions:
            if instr.instruction in ["lw","sw"]:
                ROM[fn.ROM_location + PC_offset] = instr.instruction_ROM
                ROM[fn.ROM_location + PC_offset + 1] = instr.memory_addr

                PC_offset += 2

            elif instr.instruction in ["beq","bgt","blt","goto","jr"]:

                ROM[fn.ROM_location + PC_offset] = instr.instruction_ROM
                ROM[fn.ROM_location + PC_offset + 1] =  format(fns[instr.function_target].ROM_location, '02X')

                PC_offset += 2

            elif instr.instruction in ["li"]:

                ROM[fn.ROM_location + PC_offset] = instr.instruction_ROM
                if len(instr.immediate) < 2:
                    instr.immediate = "0" + instr.immediate
                ROM[fn.ROM_location + PC_offset + 1] =  instr.immediate

                PC_offset += 2

            else:
                ROM[fn.ROM_location + PC_offset] = instr.instruction_ROM
                PC_offset += 1

    print("Finished linking")

def print_ROM(outputfile):

    output = open(outputfile, 'w')

    print("Starting to write to file")

    for instr in ROM:
        print(str(instr), file = output)

    print("Finished writing to file")
    output.close()




def run_Assembler():

    IO =  set_IO(sys.argv[1:])
    input_file = IO[0]
    output_file =IO[1]

    read_data(input_file)
    link()
    print_ROM(output_file)


run_Assembler()





                       