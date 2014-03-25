/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Finn/Downloads/Digital-System-Lab-Processor-beta-mouse-IR-instruction_demo/Digital-System-Lab-Processor-beta-mouse-IR-instruction_demo/ROM.v";
static const char *ng1 = "Complete_Demo_ROM3_LED.txt";



static void Initial_35_0(char *t0)
{
    char *t1;

LAB0:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 1904);
    xsi_vlogfile_readmemh(ng1, 0, t1, 0, 0, 0, 0);

LAB1:    return;
}

static void Always_38_1(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 3072U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 3392);
    *((int *)t2) = 1;
    t3 = (t0 + 3104);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 1904);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 1904);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 1904);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t14 = (t0 + 1344U);
    t15 = *((char **)t14);
    xsi_vlog_generic_get_array_select_value(t7, 8, t6, t10, t13, 2, 1, t15, 8, 2);
    t14 = (t0 + 1744);
    xsi_vlogvar_wait_assign_value(t14, t7, 0, 0, 8, 0LL);
    goto LAB2;

}


extern void work_m_00000000001570284185_0317860448_init()
{
	static char *pe[] = {(void *)Initial_35_0,(void *)Always_38_1};
	xsi_register_didat("work_m_00000000001570284185_0317860448", "isim/Processor_Top_isim_beh.exe.sim/work/m_00000000001570284185_0317860448.didat");
	xsi_register_executes(pe);
}
