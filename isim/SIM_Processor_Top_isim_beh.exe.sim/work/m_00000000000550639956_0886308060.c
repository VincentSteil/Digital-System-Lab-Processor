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
static const char *ng0 = "D:/DSL4/Digital-System-Lab-Processor-PS2/ALU.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static int ng6[] = {1, 0};
static unsigned int ng7[] = {4U, 0U};
static unsigned int ng8[] = {5U, 0U};
static unsigned int ng9[] = {6U, 0U};
static unsigned int ng10[] = {7U, 0U};
static unsigned int ng11[] = {8U, 0U};
static unsigned int ng12[] = {9U, 0U};
static unsigned int ng13[] = {10U, 0U};
static unsigned int ng14[] = {11U, 0U};



static void Always_35_0(char *t0)
{
    char t14[8];
    char t15[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    int t13;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;

LAB0:    t1 = (t0 + 3168U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 3736);
    *((int *)t2) = 1;
    t3 = (t0 + 3200);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);

LAB5:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(38, ng0);

LAB9:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);

LAB10:    t2 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng3)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng9)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng10)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng11)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng12)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng13)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng14)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t13 == 1)
        goto LAB33;

LAB34:
LAB36:
LAB35:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 1368U);
    t4 = *((char **)t2);
    t2 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t2, t4, 0, 0, 8, 0LL);

LAB37:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(37, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(42, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 1528U);
    t11 = *((char **)t4);
    memset(t14, 0, 8);
    xsi_vlog_unsigned_add(t14, 8, t5, 8, t11, 8);
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB13:    xsi_set_current_line(44, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 1528U);
    t11 = *((char **)t4);
    memset(t14, 0, 8);
    xsi_vlog_unsigned_minus(t14, 8, t5, 8, t11, 8);
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB15:    xsi_set_current_line(46, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 1528U);
    t11 = *((char **)t4);
    memset(t14, 0, 8);
    xsi_vlog_unsigned_multiply(t14, 8, t5, 8, t11, 8);
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB17:    xsi_set_current_line(49, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng6)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_lshift(t14, 8, t5, 8, t4, 32);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB19:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng6)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_rshift(t14, 8, t5, 8, t4, 32);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB21:    xsi_set_current_line(53, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_add(t14, 8, t5, 8, t4, 8);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB23:    xsi_set_current_line(55, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_add(t14, 8, t5, 8, t4, 8);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB25:    xsi_set_current_line(57, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_minus(t14, 8, t5, 8, t4, 8);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB27:    xsi_set_current_line(59, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_minus(t14, 8, t5, 8, t4, 8);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB29:    xsi_set_current_line(63, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 1528U);
    t11 = *((char **)t4);
    memset(t16, 0, 8);
    t4 = (t5 + 4);
    t12 = (t11 + 4);
    t6 = *((unsigned int *)t5);
    t7 = *((unsigned int *)t11);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t12);
    t17 = (t9 ^ t10);
    t18 = (t8 | t17);
    t19 = *((unsigned int *)t4);
    t20 = *((unsigned int *)t12);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB41;

LAB38:    if (t21 != 0)
        goto LAB40;

LAB39:    *((unsigned int *)t16) = 1;

LAB41:    memset(t15, 0, 8);
    t25 = (t16 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t16);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t25) != 0)
        goto LAB44;

LAB45:    t32 = (t15 + 4);
    t33 = *((unsigned int *)t15);
    t34 = *((unsigned int *)t32);
    t35 = (t33 || t34);
    if (t35 > 0)
        goto LAB46;

LAB47:    t37 = *((unsigned int *)t15);
    t38 = (~(t37));
    t39 = *((unsigned int *)t32);
    t40 = (t38 || t39);
    if (t40 > 0)
        goto LAB48;

LAB49:    if (*((unsigned int *)t32) > 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t15) > 0)
        goto LAB52;

LAB53:    memcpy(t14, t41, 8);

LAB54:    t42 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t42, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB31:    xsi_set_current_line(65, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 1528U);
    t11 = *((char **)t4);
    memset(t16, 0, 8);
    t4 = (t5 + 4);
    if (*((unsigned int *)t4) != 0)
        goto LAB56;

LAB55:    t12 = (t11 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB56;

LAB59:    if (*((unsigned int *)t5) > *((unsigned int *)t11))
        goto LAB57;

LAB58:    memset(t15, 0, 8);
    t25 = (t16 + 4);
    t6 = *((unsigned int *)t25);
    t7 = (~(t6));
    t8 = *((unsigned int *)t16);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t25) != 0)
        goto LAB62;

LAB63:    t32 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = *((unsigned int *)t32);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB64;

LAB65:    t20 = *((unsigned int *)t15);
    t21 = (~(t20));
    t22 = *((unsigned int *)t32);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t32) > 0)
        goto LAB68;

LAB69:    if (*((unsigned int *)t15) > 0)
        goto LAB70;

LAB71:    memcpy(t14, t41, 8);

LAB72:    t42 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t42, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB33:    xsi_set_current_line(67, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 1528U);
    t11 = *((char **)t4);
    memset(t16, 0, 8);
    t4 = (t5 + 4);
    if (*((unsigned int *)t4) != 0)
        goto LAB74;

LAB73:    t12 = (t11 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB74;

LAB77:    if (*((unsigned int *)t5) < *((unsigned int *)t11))
        goto LAB75;

LAB76:    memset(t15, 0, 8);
    t25 = (t16 + 4);
    t6 = *((unsigned int *)t25);
    t7 = (~(t6));
    t8 = *((unsigned int *)t16);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t25) != 0)
        goto LAB80;

LAB81:    t32 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = *((unsigned int *)t32);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB82;

LAB83:    t20 = *((unsigned int *)t15);
    t21 = (~(t20));
    t22 = *((unsigned int *)t32);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB84;

LAB85:    if (*((unsigned int *)t32) > 0)
        goto LAB86;

LAB87:    if (*((unsigned int *)t15) > 0)
        goto LAB88;

LAB89:    memcpy(t14, t41, 8);

LAB90:    t42 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t42, t14, 0, 0, 8, 0LL);
    goto LAB37;

LAB40:    t24 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB41;

LAB42:    *((unsigned int *)t15) = 1;
    goto LAB45;

LAB44:    t31 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB45;

LAB46:    t36 = ((char*)((ng3)));
    goto LAB47;

LAB48:    t41 = ((char*)((ng2)));
    goto LAB49;

LAB50:    xsi_vlog_unsigned_bit_combine(t14, 8, t36, 8, t41, 8);
    goto LAB54;

LAB52:    memcpy(t14, t36, 8);
    goto LAB54;

LAB56:    t24 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB58;

LAB57:    *((unsigned int *)t16) = 1;
    goto LAB58;

LAB60:    *((unsigned int *)t15) = 1;
    goto LAB63;

LAB62:    t31 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB63;

LAB64:    t36 = ((char*)((ng3)));
    goto LAB65;

LAB66:    t41 = ((char*)((ng2)));
    goto LAB67;

LAB68:    xsi_vlog_unsigned_bit_combine(t14, 8, t36, 8, t41, 8);
    goto LAB72;

LAB70:    memcpy(t14, t36, 8);
    goto LAB72;

LAB74:    t24 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB76;

LAB75:    *((unsigned int *)t16) = 1;
    goto LAB76;

LAB78:    *((unsigned int *)t15) = 1;
    goto LAB81;

LAB80:    t31 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB81;

LAB82:    t36 = ((char*)((ng3)));
    goto LAB83;

LAB84:    t41 = ((char*)((ng2)));
    goto LAB85;

LAB86:    xsi_vlog_unsigned_bit_combine(t14, 8, t36, 8, t41, 8);
    goto LAB90;

LAB88:    memcpy(t14, t36, 8);
    goto LAB90;

}

static void Cont_74_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 3416U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3832);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 7);
    t18 = (t0 + 3752);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_00000000000550639956_0886308060_init()
{
	static char *pe[] = {(void *)Always_35_0,(void *)Cont_74_1};
	xsi_register_didat("work_m_00000000000550639956_0886308060", "isim/SIM_Processor_Top_isim_beh.exe.sim/work/m_00000000000550639956_0886308060.didat");
	xsi_register_executes(pe);
}
