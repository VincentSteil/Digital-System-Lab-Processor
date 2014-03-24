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
static const char *ng0 = "D:/DSL4/Digital-System-Lab-Processor-PS2/IO_Bus_Mouse.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {0U, 255U};
static const char *ng4 = "Mouse.txt";
static unsigned int ng5[] = {160U, 0U};
static int ng6[] = {2, 0};
static int ng7[] = {0, 0};
static int ng8[] = {1, 0};



static void Always_62_0(char *t0)
{
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

LAB0:    t1 = (t0 + 5360U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 7168);
    *((int *)t2) = 1;
    t3 = (t0 + 5392);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(63, ng0);

LAB5:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 1480U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 3240U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2600U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB12;

LAB13:
LAB14:
LAB11:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(65, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3960);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    goto LAB8;

LAB9:    xsi_set_current_line(67, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 3960);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB11;

LAB12:    xsi_set_current_line(69, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 3960);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB14;

}

static void Cont_72_1(char *t0)
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

LAB0:    t1 = (t0 + 5608U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 3960);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7328);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 7184);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_84_2(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;

LAB0:    t1 = (t0 + 5856U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 4280);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t14);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t25, 8);

LAB16:    t26 = (t0 + 7392);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    memset(t30, 0, 8);
    t31 = 255U;
    t32 = t31;
    t33 = (t3 + 4);
    t34 = *((unsigned int *)t3);
    t31 = (t31 & t34);
    t35 = *((unsigned int *)t33);
    t32 = (t32 & t35);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t37 | t31);
    t38 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t38 | t32);
    xsi_driver_vfirst_trans(t26, 0, 7);
    t39 = (t0 + 7200);
    *((int *)t39) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 4120);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    goto LAB9;

LAB10:    t25 = ((char*)((ng3)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 8, t20, 8, t25, 8);
    goto LAB16;

LAB14:    memcpy(t3, t20, 8);
    goto LAB16;

}

static void Cont_85_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 6104U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 1640U);
    t3 = *((char **)t2);
    t2 = (t0 + 7456);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 255U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 7);
    t16 = (t0 + 7216);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Initial_91_4(char *t0)
{
    char *t1;

LAB0:    xsi_set_current_line(91, ng0);
    t1 = (t0 + 4440);
    xsi_vlogfile_readmemh(ng4, 0, t1, 0, 0, 0, 0);

LAB1:    return;
}

static void Cont_95_5(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t15[8];
    char t16[8];
    char t17[8];
    char t20[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    int t44;
    int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;

LAB0:    t1 = (t0 + 6600U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 1800U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB5;

LAB4:    t8 = (t2 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB5;

LAB8:    if (*((unsigned int *)t5) < *((unsigned int *)t2))
        goto LAB7;

LAB6:    *((unsigned int *)t6) = 1;

LAB7:    t10 = (t0 + 1800U);
    t11 = *((char **)t10);
    t10 = ((char*)((ng5)));
    t12 = ((char*)((ng6)));
    t13 = (t0 + 608);
    t14 = *((char **)t13);
    memset(t15, 0, 8);
    xsi_vlog_unsigned_power(t15, 32, t12, 32, t14, 32, 1);
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t10, 8, t15, 32);
    memset(t17, 0, 8);
    t13 = (t11 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB10;

LAB9:    t18 = (t16 + 4);
    if (*((unsigned int *)t18) != 0)
        goto LAB10;

LAB13:    if (*((unsigned int *)t11) < *((unsigned int *)t16))
        goto LAB11;

LAB12:    t21 = *((unsigned int *)t6);
    t22 = *((unsigned int *)t17);
    t23 = (t21 & t22);
    *((unsigned int *)t20) = t23;
    t24 = (t6 + 4);
    t25 = (t17 + 4);
    t26 = (t20 + 4);
    t27 = *((unsigned int *)t24);
    t28 = *((unsigned int *)t25);
    t29 = (t27 | t28);
    *((unsigned int *)t26) = t29;
    t30 = *((unsigned int *)t26);
    t31 = (t30 != 0);
    if (t31 == 1)
        goto LAB14;

LAB15:
LAB16:    memset(t4, 0, 8);
    t52 = (t20 + 4);
    t53 = *((unsigned int *)t52);
    t54 = (~(t53));
    t55 = *((unsigned int *)t20);
    t56 = (t55 & t54);
    t57 = (t56 & 1U);
    if (t57 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t52) != 0)
        goto LAB19;

LAB20:    t59 = (t4 + 4);
    t60 = *((unsigned int *)t4);
    t61 = *((unsigned int *)t59);
    t62 = (t60 || t61);
    if (t62 > 0)
        goto LAB21;

LAB22:    t64 = *((unsigned int *)t4);
    t65 = (~(t64));
    t66 = *((unsigned int *)t59);
    t67 = (t65 || t66);
    if (t67 > 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t59) > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t4) > 0)
        goto LAB27;

LAB28:    memcpy(t3, t68, 8);

LAB29:    t69 = (t0 + 7520);
    t70 = (t69 + 56U);
    t71 = *((char **)t70);
    t72 = (t71 + 56U);
    t73 = *((char **)t72);
    memset(t73, 0, 8);
    t74 = 1U;
    t75 = t74;
    t76 = (t3 + 4);
    t77 = *((unsigned int *)t3);
    t74 = (t74 & t77);
    t78 = *((unsigned int *)t76);
    t75 = (t75 & t78);
    t79 = (t73 + 4);
    t80 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t80 | t74);
    t81 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t81 | t75);
    xsi_driver_vfirst_trans(t69, 0, 0);
    t82 = (t0 + 7232);
    *((int *)t82) = 1;

LAB1:    return;
LAB5:    t9 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB7;

LAB10:    t19 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB12;

LAB11:    *((unsigned int *)t17) = 1;
    goto LAB12;

LAB14:    t32 = *((unsigned int *)t20);
    t33 = *((unsigned int *)t26);
    *((unsigned int *)t20) = (t32 | t33);
    t34 = (t6 + 4);
    t35 = (t17 + 4);
    t36 = *((unsigned int *)t6);
    t37 = (~(t36));
    t38 = *((unsigned int *)t34);
    t39 = (~(t38));
    t40 = *((unsigned int *)t17);
    t41 = (~(t40));
    t42 = *((unsigned int *)t35);
    t43 = (~(t42));
    t44 = (t37 & t39);
    t45 = (t41 & t43);
    t46 = (~(t44));
    t47 = (~(t45));
    t48 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t48 & t46);
    t49 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t49 & t47);
    t50 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t50 & t46);
    t51 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t51 & t47);
    goto LAB16;

LAB17:    *((unsigned int *)t4) = 1;
    goto LAB20;

LAB19:    t58 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB20;

LAB21:    t63 = ((char*)((ng2)));
    goto LAB22;

LAB23:    t68 = ((char*)((ng1)));
    goto LAB24;

LAB25:    xsi_vlog_unsigned_bit_combine(t3, 1, t63, 1, t68, 1);
    goto LAB29;

LAB27:    memcpy(t3, t63, 8);
    goto LAB29;

}

static void Always_98_6(char *t0)
{
    char t4[8];
    char t8[8];
    char t9[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    int t19;
    char *t20;
    unsigned int t21;
    int t22;
    int t23;
    unsigned int t24;
    unsigned int t25;
    int t26;
    int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;

LAB0:    t1 = (t0 + 6848U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 7248);
    *((int *)t2) = 1;
    t3 = (t0 + 6880);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(99, ng0);

LAB5:    xsi_set_current_line(103, ng0);
    t5 = (t0 + 2760U);
    t6 = *((char **)t5);
    t5 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 8, 8, 2U, t5, 4, t6, 4);
    t7 = (t0 + 4440);
    t10 = (t0 + 4440);
    t11 = (t10 + 72U);
    t12 = *((char **)t11);
    t13 = (t0 + 4440);
    t14 = (t13 + 64U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng7)));
    xsi_vlog_generic_convert_array_indices(t8, t9, t12, t15, 2, 1, t16, 32, 1);
    t17 = (t8 + 4);
    t18 = *((unsigned int *)t17);
    t19 = (!(t18));
    t20 = (t9 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (!(t21));
    t23 = (t19 && t22);
    if (t23 == 1)
        goto LAB6;

LAB7:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 2920U);
    t3 = *((char **)t2);
    t2 = (t0 + 4440);
    t5 = (t0 + 4440);
    t6 = (t5 + 72U);
    t7 = *((char **)t6);
    t10 = (t0 + 4440);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng8)));
    xsi_vlog_generic_convert_array_indices(t4, t8, t7, t12, 2, 1, t13, 32, 1);
    t14 = (t4 + 4);
    t18 = *((unsigned int *)t14);
    t19 = (!(t18));
    t15 = (t8 + 4);
    t21 = *((unsigned int *)t15);
    t22 = (!(t21));
    t23 = (t19 && t22);
    if (t23 == 1)
        goto LAB8;

LAB9:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 3080U);
    t3 = *((char **)t2);
    t2 = (t0 + 4440);
    t5 = (t0 + 4440);
    t6 = (t5 + 72U);
    t7 = *((char **)t6);
    t10 = (t0 + 4440);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t4, t8, t7, t12, 2, 1, t13, 32, 1);
    t14 = (t4 + 4);
    t18 = *((unsigned int *)t14);
    t19 = (!(t18));
    t15 = (t8 + 4);
    t21 = *((unsigned int *)t15);
    t22 = (!(t21));
    t23 = (t19 && t22);
    if (t23 == 1)
        goto LAB10;

LAB11:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 3560U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t18 = *((unsigned int *)t2);
    t21 = (~(t18));
    t24 = *((unsigned int *)t3);
    t25 = (t24 & t21);
    t28 = (t25 != 0);
    if (t28 > 0)
        goto LAB12;

LAB13:    xsi_set_current_line(120, ng0);

LAB23:    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4280);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB14:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 4440);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 4440);
    t7 = (t6 + 72U);
    t10 = *((char **)t7);
    t11 = (t0 + 4440);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t14 = (t0 + 1800U);
    t15 = *((char **)t14);
    memset(t8, 0, 8);
    t14 = (t8 + 4);
    t16 = (t15 + 4);
    t18 = *((unsigned int *)t15);
    t21 = (t18 >> 0);
    *((unsigned int *)t8) = t21;
    t24 = *((unsigned int *)t16);
    t25 = (t24 >> 0);
    *((unsigned int *)t14) = t25;
    t28 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t28 & 15U);
    t29 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t29 & 15U);
    xsi_vlog_generic_get_array_select_value(t4, 8, t5, t10, t13, 2, 1, t8, 4, 2);
    t17 = (t0 + 4120);
    xsi_vlogvar_wait_assign_value(t17, t4, 0, 0, 8, 0LL);
    goto LAB2;

LAB6:    t24 = *((unsigned int *)t8);
    t25 = *((unsigned int *)t9);
    t26 = (t24 - t25);
    t27 = (t26 + 1);
    xsi_vlogvar_wait_assign_value(t7, t4, 0, *((unsigned int *)t9), t27, 0LL);
    goto LAB7;

LAB8:    t24 = *((unsigned int *)t4);
    t25 = *((unsigned int *)t8);
    t26 = (t24 - t25);
    t27 = (t26 + 1);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, *((unsigned int *)t8), t27, 0LL);
    goto LAB9;

LAB10:    t24 = *((unsigned int *)t4);
    t25 = *((unsigned int *)t8);
    t26 = (t24 - t25);
    t27 = (t26 + 1);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, *((unsigned int *)t8), t27, 0LL);
    goto LAB11;

LAB12:    xsi_set_current_line(108, ng0);

LAB15:    xsi_set_current_line(109, ng0);
    t5 = (t0 + 1960U);
    t6 = *((char **)t5);
    t5 = (t6 + 4);
    t29 = *((unsigned int *)t5);
    t30 = (~(t29));
    t31 = *((unsigned int *)t6);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(115, ng0);

LAB22:    xsi_set_current_line(116, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4280);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB18:    goto LAB14;

LAB16:    xsi_set_current_line(110, ng0);

LAB19:    xsi_set_current_line(111, ng0);
    t7 = (t0 + 3400U);
    t10 = *((char **)t7);
    t7 = (t0 + 4440);
    t11 = (t0 + 4440);
    t12 = (t11 + 72U);
    t13 = *((char **)t12);
    t14 = (t0 + 4440);
    t15 = (t14 + 64U);
    t16 = *((char **)t15);
    t17 = (t0 + 1800U);
    t20 = *((char **)t17);
    memset(t9, 0, 8);
    t17 = (t9 + 4);
    t34 = (t20 + 4);
    t35 = *((unsigned int *)t20);
    t36 = (t35 >> 0);
    *((unsigned int *)t9) = t36;
    t37 = *((unsigned int *)t34);
    t38 = (t37 >> 0);
    *((unsigned int *)t17) = t38;
    t39 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t39 & 15U);
    t40 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t40 & 15U);
    xsi_vlog_generic_convert_array_indices(t4, t8, t13, t16, 2, 1, t9, 4, 2);
    t41 = (t4 + 4);
    t42 = *((unsigned int *)t41);
    t19 = (!(t42));
    t43 = (t8 + 4);
    t44 = *((unsigned int *)t43);
    t22 = (!(t44));
    t23 = (t19 && t22);
    if (t23 == 1)
        goto LAB20;

LAB21:    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4280);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB18;

LAB20:    t45 = *((unsigned int *)t4);
    t46 = *((unsigned int *)t8);
    t26 = (t45 - t46);
    t27 = (t26 + 1);
    xsi_vlogvar_wait_assign_value(t7, t10, 0, *((unsigned int *)t8), t27, 0LL);
    goto LAB21;

}


extern void work_m_00000000003467754451_0959797785_init()
{
	static char *pe[] = {(void *)Always_62_0,(void *)Cont_72_1,(void *)Cont_84_2,(void *)Cont_85_3,(void *)Initial_91_4,(void *)Cont_95_5,(void *)Always_98_6};
	xsi_register_didat("work_m_00000000003467754451_0959797785", "isim/SIM_Processor_Top_isim_beh.exe.sim/work/m_00000000003467754451_0959797785.didat");
	xsi_register_executes(pe);
}
