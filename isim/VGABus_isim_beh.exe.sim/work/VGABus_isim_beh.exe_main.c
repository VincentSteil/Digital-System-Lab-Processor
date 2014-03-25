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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000000167007274_0632413944_init();
    work_m_00000000003487995058_2250638391_init();
    work_m_00000000003487995058_4055406612_init();
    work_m_00000000000806602238_2589612675_init();
    work_m_00000000003441444710_0766461805_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000003441444710_0766461805");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
