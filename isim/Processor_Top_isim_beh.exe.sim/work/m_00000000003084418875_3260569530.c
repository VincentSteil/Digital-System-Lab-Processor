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
static const char *ng0 = "C:/Users/Finn/Downloads/Digital-System-Lab-Processor-beta-mouse-IR-instruction_demo/Digital-System-Lab-Processor-beta-mouse-IR-instruction_demo/MouseReceiver.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {1, 0};
static int ng5[] = {50000, 0};
static int ng6[] = {8, 0};
static int ng7[] = {2, 0};
static int ng8[] = {6, 0};
static int ng9[] = {7, 0};
static int ng10[] = {3, 0};
static int ng11[] = {100000, 0};
static int ng12[] = {4, 0};



static void Always_40_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 5408U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 6968);
    *((int *)t2) = 1;
    t3 = (t0 + 5440);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 0LL);
    goto LAB2;

}

static void Always_53_1(char *t0)
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

LAB0:    t1 = (t0 + 5656U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 6984);
    *((int *)t2) = 1;
    t3 = (t0 + 5688);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(54, ng0);

LAB5:    xsi_set_current_line(55, ng0);
    t4 = (t0 + 1048U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(65, ng0);

LAB10:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 3528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(70, ng0);
    t2 = (t0 + 4168);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4008);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 4488);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4328);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 16, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(56, ng0);

LAB9:    xsi_set_current_line(57, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 0LL);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4008);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4328);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    goto LAB8;

}

static void Always_76_2(char *t0)
{
    char t8[8];
    char t43[8];
    char t62[8];
    char t94[8];
    char t113[8];
    char t153[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    char *t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    int t86;
    int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    char *t95;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    char *t102;
    char *t103;
    char *t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    char *t118;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    char *t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    int t137;
    int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    char *t151;
    char *t152;
    int t154;
    int t155;
    int t156;

LAB0:    t1 = (t0 + 5904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 7000);
    *((int *)t2) = 1;
    t3 = (t0 + 5936);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(77, ng0);

LAB5:    xsi_set_current_line(79, ng0);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2888);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    xsi_set_current_line(80, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3208);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3528);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 4008);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4168);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 2);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 4328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 16, t4, 16, t5, 16);
    t6 = (t0 + 4488);
    xsi_vlogvar_assign_value(t6, t8, 0, 0, 16);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng1)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 32);
    if (t9 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 32);
    if (t9 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng7)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 32);
    if (t9 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng10)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 32);
    if (t9 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng12)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 32);
    if (t9 == 1)
        goto LAB15;

LAB16:
LAB18:
LAB17:    xsi_set_current_line(169, ng0);

LAB148:    xsi_set_current_line(171, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(172, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(173, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(174, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(175, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4168);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(176, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);

LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(89, ng0);

LAB20:    xsi_set_current_line(91, ng0);
    t6 = (t0 + 1688U);
    t7 = *((char **)t6);
    t6 = (t0 + 2568);
    t10 = (t6 + 56U);
    t11 = *((char **)t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t11);
    t14 = (t12 & t13);
    *((unsigned int *)t8) = t14;
    t15 = (t7 + 4);
    t16 = (t11 + 4);
    t17 = (t8 + 4);
    t18 = *((unsigned int *)t15);
    t19 = *((unsigned int *)t16);
    t20 = (t18 | t19);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB21;

LAB22:
LAB23:    t44 = (t0 + 1368U);
    t45 = *((char **)t44);
    memset(t43, 0, 8);
    t44 = (t45 + 4);
    t46 = *((unsigned int *)t44);
    t47 = (~(t46));
    t48 = *((unsigned int *)t45);
    t49 = (t48 & t47);
    t50 = (t49 & 1U);
    if (t50 != 0)
        goto LAB27;

LAB25:    if (*((unsigned int *)t44) == 0)
        goto LAB24;

LAB26:    t51 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t51) = 1;

LAB27:    t52 = (t43 + 4);
    t53 = (t45 + 4);
    t54 = *((unsigned int *)t45);
    t55 = (~(t54));
    *((unsigned int *)t43) = t55;
    *((unsigned int *)t52) = 0;
    if (*((unsigned int *)t53) != 0)
        goto LAB29;

LAB28:    t60 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t60 & 1U);
    t61 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t61 & 1U);
    t63 = *((unsigned int *)t8);
    t64 = *((unsigned int *)t43);
    t65 = (t63 & t64);
    *((unsigned int *)t62) = t65;
    t66 = (t8 + 4);
    t67 = (t43 + 4);
    t68 = (t62 + 4);
    t69 = *((unsigned int *)t66);
    t70 = *((unsigned int *)t67);
    t71 = (t69 | t70);
    *((unsigned int *)t68) = t71;
    t72 = *((unsigned int *)t68);
    t73 = (t72 != 0);
    if (t73 == 1)
        goto LAB30;

LAB31:
LAB32:    t95 = (t0 + 1528U);
    t96 = *((char **)t95);
    memset(t94, 0, 8);
    t95 = (t96 + 4);
    t97 = *((unsigned int *)t95);
    t98 = (~(t97));
    t99 = *((unsigned int *)t96);
    t100 = (t99 & t98);
    t101 = (t100 & 1U);
    if (t101 != 0)
        goto LAB36;

LAB34:    if (*((unsigned int *)t95) == 0)
        goto LAB33;

LAB35:    t102 = (t94 + 4);
    *((unsigned int *)t94) = 1;
    *((unsigned int *)t102) = 1;

LAB36:    t103 = (t94 + 4);
    t104 = (t96 + 4);
    t105 = *((unsigned int *)t96);
    t106 = (~(t105));
    *((unsigned int *)t94) = t106;
    *((unsigned int *)t103) = 0;
    if (*((unsigned int *)t104) != 0)
        goto LAB38;

LAB37:    t111 = *((unsigned int *)t94);
    *((unsigned int *)t94) = (t111 & 1U);
    t112 = *((unsigned int *)t103);
    *((unsigned int *)t103) = (t112 & 1U);
    t114 = *((unsigned int *)t62);
    t115 = *((unsigned int *)t94);
    t116 = (t114 & t115);
    *((unsigned int *)t113) = t116;
    t117 = (t62 + 4);
    t118 = (t94 + 4);
    t119 = (t113 + 4);
    t120 = *((unsigned int *)t117);
    t121 = *((unsigned int *)t118);
    t122 = (t120 | t121);
    *((unsigned int *)t119) = t122;
    t123 = *((unsigned int *)t119);
    t124 = (t123 != 0);
    if (t124 == 1)
        goto LAB39;

LAB40:
LAB41:    t145 = (t113 + 4);
    t146 = *((unsigned int *)t145);
    t147 = (~(t146));
    t148 = *((unsigned int *)t113);
    t149 = (t148 & t147);
    t150 = (t149 != 0);
    if (t150 > 0)
        goto LAB42;

LAB43:
LAB44:    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB19;

LAB9:    xsi_set_current_line(102, ng0);

LAB46:    xsi_set_current_line(103, ng0);
    t3 = (t0 + 4328);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng5)));
    memset(t8, 0, 8);
    t10 = (t6 + 4);
    t11 = (t7 + 4);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    t14 = (t12 ^ t13);
    t18 = *((unsigned int *)t10);
    t19 = *((unsigned int *)t11);
    t20 = (t18 ^ t19);
    t21 = (t14 | t20);
    t22 = *((unsigned int *)t10);
    t23 = *((unsigned int *)t11);
    t24 = (t22 | t23);
    t27 = (~(t24));
    t28 = (t21 & t27);
    if (t28 != 0)
        goto LAB50;

LAB47:    if (t24 != 0)
        goto LAB49;

LAB48:    *((unsigned int *)t8) = 1;

LAB50:    t16 = (t8 + 4);
    t29 = *((unsigned int *)t16);
    t30 = (~(t29));
    t31 = *((unsigned int *)t8);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB51;

LAB52:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t8, 0, 8);
    t7 = (t5 + 4);
    t10 = (t6 + 4);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t6);
    t14 = (t12 ^ t13);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t10);
    t20 = (t18 ^ t19);
    t21 = (t14 | t20);
    t22 = *((unsigned int *)t7);
    t23 = *((unsigned int *)t10);
    t24 = (t22 | t23);
    t27 = (~(t24));
    t28 = (t21 & t27);
    if (t28 != 0)
        goto LAB57;

LAB54:    if (t24 != 0)
        goto LAB56;

LAB55:    *((unsigned int *)t8) = 1;

LAB57:    t15 = (t8 + 4);
    t29 = *((unsigned int *)t15);
    t30 = (~(t29));
    t31 = *((unsigned int *)t8);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB58;

LAB59:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1368U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t6 = (t7 + 4);
    t12 = *((unsigned int *)t6);
    t13 = (~(t12));
    t14 = *((unsigned int *)t7);
    t18 = (t14 & t13);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB65;

LAB63:    if (*((unsigned int *)t6) == 0)
        goto LAB62;

LAB64:    t10 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t10) = 1;

LAB65:    t11 = (t8 + 4);
    t15 = (t7 + 4);
    t20 = *((unsigned int *)t7);
    t21 = (~(t20));
    *((unsigned int *)t8) = t21;
    *((unsigned int *)t11) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB67;

LAB66:    t28 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t28 & 1U);
    t29 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t29 & 1U);
    t30 = *((unsigned int *)t5);
    t31 = *((unsigned int *)t8);
    t32 = (t30 & t31);
    *((unsigned int *)t43) = t32;
    t16 = (t5 + 4);
    t17 = (t8 + 4);
    t25 = (t43 + 4);
    t33 = *((unsigned int *)t16);
    t34 = *((unsigned int *)t17);
    t37 = (t33 | t34);
    *((unsigned int *)t25) = t37;
    t38 = *((unsigned int *)t25);
    t39 = (t38 != 0);
    if (t39 == 1)
        goto LAB68;

LAB69:
LAB70:    t45 = (t43 + 4);
    t63 = *((unsigned int *)t45);
    t64 = (~(t63));
    t65 = *((unsigned int *)t43);
    t69 = (t65 & t64);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB71;

LAB72:
LAB73:
LAB60:
LAB53:    goto LAB19;

LAB11:    xsi_set_current_line(121, ng0);

LAB79:    xsi_set_current_line(123, ng0);
    t3 = (t0 + 4328);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng5)));
    memset(t8, 0, 8);
    t10 = (t6 + 4);
    t11 = (t7 + 4);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    t14 = (t12 ^ t13);
    t18 = *((unsigned int *)t10);
    t19 = *((unsigned int *)t11);
    t20 = (t18 ^ t19);
    t21 = (t14 | t20);
    t22 = *((unsigned int *)t10);
    t23 = *((unsigned int *)t11);
    t24 = (t22 | t23);
    t27 = (~(t24));
    t28 = (t21 & t27);
    if (t28 != 0)
        goto LAB83;

LAB80:    if (t24 != 0)
        goto LAB82;

LAB81:    *((unsigned int *)t8) = 1;

LAB83:    t16 = (t8 + 4);
    t29 = *((unsigned int *)t16);
    t30 = (~(t29));
    t31 = *((unsigned int *)t8);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB84;

LAB85:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1368U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t6 = (t7 + 4);
    t12 = *((unsigned int *)t6);
    t13 = (~(t12));
    t14 = *((unsigned int *)t7);
    t18 = (t14 & t13);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB90;

LAB88:    if (*((unsigned int *)t6) == 0)
        goto LAB87;

LAB89:    t10 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t10) = 1;

LAB90:    t11 = (t8 + 4);
    t15 = (t7 + 4);
    t20 = *((unsigned int *)t7);
    t21 = (~(t20));
    *((unsigned int *)t8) = t21;
    *((unsigned int *)t11) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB92;

LAB91:    t28 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t28 & 1U);
    t29 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t29 & 1U);
    t30 = *((unsigned int *)t5);
    t31 = *((unsigned int *)t8);
    t32 = (t30 & t31);
    *((unsigned int *)t43) = t32;
    t16 = (t5 + 4);
    t17 = (t8 + 4);
    t25 = (t43 + 4);
    t33 = *((unsigned int *)t16);
    t34 = *((unsigned int *)t17);
    t37 = (t33 | t34);
    *((unsigned int *)t25) = t37;
    t38 = *((unsigned int *)t25);
    t39 = (t38 != 0);
    if (t39 == 1)
        goto LAB93;

LAB94:
LAB95:    t45 = (t43 + 4);
    t63 = *((unsigned int *)t45);
    t64 = (~(t63));
    t65 = *((unsigned int *)t43);
    t69 = (t65 & t64);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB96;

LAB97:
LAB98:
LAB86:    goto LAB19;

LAB13:    xsi_set_current_line(145, ng0);

LAB119:    xsi_set_current_line(147, ng0);
    t3 = (t0 + 4328);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng11)));
    memset(t8, 0, 8);
    t10 = (t6 + 4);
    t11 = (t7 + 4);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    t14 = (t12 ^ t13);
    t18 = *((unsigned int *)t10);
    t19 = *((unsigned int *)t11);
    t20 = (t18 ^ t19);
    t21 = (t14 | t20);
    t22 = *((unsigned int *)t10);
    t23 = *((unsigned int *)t11);
    t24 = (t22 | t23);
    t27 = (~(t24));
    t28 = (t21 & t27);
    if (t28 != 0)
        goto LAB123;

LAB120:    if (t24 != 0)
        goto LAB122;

LAB121:    *((unsigned int *)t8) = 1;

LAB123:    t16 = (t8 + 4);
    t29 = *((unsigned int *)t16);
    t30 = (~(t29));
    t31 = *((unsigned int *)t8);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB124;

LAB125:    xsi_set_current_line(149, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1368U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t6 = (t7 + 4);
    t12 = *((unsigned int *)t6);
    t13 = (~(t12));
    t14 = *((unsigned int *)t7);
    t18 = (t14 & t13);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB130;

LAB128:    if (*((unsigned int *)t6) == 0)
        goto LAB127;

LAB129:    t10 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t10) = 1;

LAB130:    t11 = (t8 + 4);
    t15 = (t7 + 4);
    t20 = *((unsigned int *)t7);
    t21 = (~(t20));
    *((unsigned int *)t8) = t21;
    *((unsigned int *)t11) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB132;

LAB131:    t28 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t28 & 1U);
    t29 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t29 & 1U);
    t30 = *((unsigned int *)t5);
    t31 = *((unsigned int *)t8);
    t32 = (t30 & t31);
    *((unsigned int *)t43) = t32;
    t16 = (t5 + 4);
    t17 = (t8 + 4);
    t25 = (t43 + 4);
    t33 = *((unsigned int *)t16);
    t34 = *((unsigned int *)t17);
    t37 = (t33 | t34);
    *((unsigned int *)t25) = t37;
    t38 = *((unsigned int *)t25);
    t39 = (t38 != 0);
    if (t39 == 1)
        goto LAB133;

LAB134:
LAB135:    t45 = (t43 + 4);
    t63 = *((unsigned int *)t45);
    t64 = (~(t63));
    t65 = *((unsigned int *)t43);
    t69 = (t65 & t64);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB136;

LAB137:
LAB138:
LAB126:    goto LAB19;

LAB15:    xsi_set_current_line(162, ng0);

LAB147:    xsi_set_current_line(164, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 3848);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB19;

LAB21:    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t8) = (t23 | t24);
    t25 = (t7 + 4);
    t26 = (t11 + 4);
    t27 = *((unsigned int *)t7);
    t28 = (~(t27));
    t29 = *((unsigned int *)t25);
    t30 = (~(t29));
    t31 = *((unsigned int *)t11);
    t32 = (~(t31));
    t33 = *((unsigned int *)t26);
    t34 = (~(t33));
    t35 = (t28 & t30);
    t36 = (t32 & t34);
    t37 = (~(t35));
    t38 = (~(t36));
    t39 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t39 & t37);
    t40 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t40 & t38);
    t41 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t41 & t37);
    t42 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t42 & t38);
    goto LAB23;

LAB24:    *((unsigned int *)t43) = 1;
    goto LAB27;

LAB29:    t56 = *((unsigned int *)t43);
    t57 = *((unsigned int *)t53);
    *((unsigned int *)t43) = (t56 | t57);
    t58 = *((unsigned int *)t52);
    t59 = *((unsigned int *)t53);
    *((unsigned int *)t52) = (t58 | t59);
    goto LAB28;

LAB30:    t74 = *((unsigned int *)t62);
    t75 = *((unsigned int *)t68);
    *((unsigned int *)t62) = (t74 | t75);
    t76 = (t8 + 4);
    t77 = (t43 + 4);
    t78 = *((unsigned int *)t8);
    t79 = (~(t78));
    t80 = *((unsigned int *)t76);
    t81 = (~(t80));
    t82 = *((unsigned int *)t43);
    t83 = (~(t82));
    t84 = *((unsigned int *)t77);
    t85 = (~(t84));
    t86 = (t79 & t81);
    t87 = (t83 & t85);
    t88 = (~(t86));
    t89 = (~(t87));
    t90 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t90 & t88);
    t91 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t91 & t89);
    t92 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t92 & t88);
    t93 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t93 & t89);
    goto LAB32;

LAB33:    *((unsigned int *)t94) = 1;
    goto LAB36;

LAB38:    t107 = *((unsigned int *)t94);
    t108 = *((unsigned int *)t104);
    *((unsigned int *)t94) = (t107 | t108);
    t109 = *((unsigned int *)t103);
    t110 = *((unsigned int *)t104);
    *((unsigned int *)t103) = (t109 | t110);
    goto LAB37;

LAB39:    t125 = *((unsigned int *)t113);
    t126 = *((unsigned int *)t119);
    *((unsigned int *)t113) = (t125 | t126);
    t127 = (t62 + 4);
    t128 = (t94 + 4);
    t129 = *((unsigned int *)t62);
    t130 = (~(t129));
    t131 = *((unsigned int *)t127);
    t132 = (~(t131));
    t133 = *((unsigned int *)t94);
    t134 = (~(t133));
    t135 = *((unsigned int *)t128);
    t136 = (~(t135));
    t137 = (t130 & t132);
    t138 = (t134 & t136);
    t139 = (~(t137));
    t140 = (~(t138));
    t141 = *((unsigned int *)t119);
    *((unsigned int *)t119) = (t141 & t139);
    t142 = *((unsigned int *)t119);
    *((unsigned int *)t119) = (t142 & t140);
    t143 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t143 & t139);
    t144 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t144 & t140);
    goto LAB41;

LAB42:    xsi_set_current_line(92, ng0);

LAB45:    xsi_set_current_line(93, ng0);
    t151 = ((char*)((ng4)));
    t152 = (t0 + 2888);
    xsi_vlogvar_assign_value(t152, t151, 0, 0, 3);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4168);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    goto LAB44;

LAB49:    t15 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB50;

LAB51:    xsi_set_current_line(104, ng0);
    t17 = ((char*)((ng1)));
    t25 = (t0 + 2888);
    xsi_vlogvar_assign_value(t25, t17, 0, 0, 3);
    goto LAB53;

LAB56:    t11 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB57;

LAB58:    xsi_set_current_line(106, ng0);

LAB61:    xsi_set_current_line(107, ng0);
    t16 = ((char*)((ng7)));
    t17 = (t0 + 2888);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 3);
    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB60;

LAB62:    *((unsigned int *)t8) = 1;
    goto LAB65;

LAB67:    t22 = *((unsigned int *)t8);
    t23 = *((unsigned int *)t15);
    *((unsigned int *)t8) = (t22 | t23);
    t24 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t15);
    *((unsigned int *)t11) = (t24 | t27);
    goto LAB66;

LAB68:    t40 = *((unsigned int *)t43);
    t41 = *((unsigned int *)t25);
    *((unsigned int *)t43) = (t40 | t41);
    t26 = (t5 + 4);
    t44 = (t8 + 4);
    t42 = *((unsigned int *)t5);
    t46 = (~(t42));
    t47 = *((unsigned int *)t26);
    t48 = (~(t47));
    t49 = *((unsigned int *)t8);
    t50 = (~(t49));
    t54 = *((unsigned int *)t44);
    t55 = (~(t54));
    t9 = (t46 & t48);
    t35 = (t50 & t55);
    t56 = (~(t9));
    t57 = (~(t35));
    t58 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t58 & t56);
    t59 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t59 & t57);
    t60 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t60 & t56);
    t61 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t61 & t57);
    goto LAB70;

LAB71:    xsi_set_current_line(111, ng0);

LAB74:    xsi_set_current_line(112, ng0);
    t51 = (t0 + 3048);
    t52 = (t51 + 56U);
    t53 = *((char **)t52);
    memset(t62, 0, 8);
    t66 = (t62 + 4);
    t67 = (t53 + 4);
    t71 = *((unsigned int *)t53);
    t72 = (t71 >> 1);
    *((unsigned int *)t62) = t72;
    t73 = *((unsigned int *)t67);
    t74 = (t73 >> 1);
    *((unsigned int *)t66) = t74;
    t75 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t75 & 127U);
    t78 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t78 & 127U);
    t68 = (t0 + 3208);
    t76 = (t0 + 3208);
    t77 = (t76 + 72U);
    t95 = *((char **)t77);
    t96 = ((char*)((ng8)));
    t102 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t94, t113, t153, ((int*)(t95)), 2, t96, 32, 1, t102, 32, 1);
    t103 = (t94 + 4);
    t79 = *((unsigned int *)t103);
    t36 = (!(t79));
    t104 = (t113 + 4);
    t80 = *((unsigned int *)t104);
    t86 = (!(t80));
    t87 = (t36 && t86);
    t117 = (t153 + 4);
    t81 = *((unsigned int *)t117);
    t137 = (!(t81));
    t138 = (t87 && t137);
    if (t138 == 1)
        goto LAB75;

LAB76:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 3208);
    t5 = (t0 + 3208);
    t6 = (t5 + 72U);
    t7 = *((char **)t6);
    t10 = ((char*)((ng9)));
    xsi_vlog_generic_convert_bit_index(t8, t7, 2, t10, 32, 1);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t11);
    t9 = (!(t12));
    if (t9 == 1)
        goto LAB77;

LAB78:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t5, 4, t6, 32);
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t8, 0, 0, 4);
    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    goto LAB73;

LAB75:    t82 = *((unsigned int *)t153);
    t154 = (t82 + 0);
    t83 = *((unsigned int *)t94);
    t84 = *((unsigned int *)t113);
    t155 = (t83 - t84);
    t156 = (t155 + 1);
    xsi_vlogvar_assign_value(t68, t62, t154, *((unsigned int *)t113), t156);
    goto LAB76;

LAB77:    xsi_vlogvar_assign_value(t2, t3, 0, *((unsigned int *)t8), 1);
    goto LAB78;

LAB82:    t15 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB83;

LAB84:    xsi_set_current_line(124, ng0);
    t17 = ((char*)((ng1)));
    t25 = (t0 + 2888);
    xsi_vlogvar_assign_value(t25, t17, 0, 0, 3);
    goto LAB86;

LAB87:    *((unsigned int *)t8) = 1;
    goto LAB90;

LAB92:    t22 = *((unsigned int *)t8);
    t23 = *((unsigned int *)t15);
    *((unsigned int *)t8) = (t22 | t23);
    t24 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t15);
    *((unsigned int *)t11) = (t24 | t27);
    goto LAB91;

LAB93:    t40 = *((unsigned int *)t43);
    t41 = *((unsigned int *)t25);
    *((unsigned int *)t43) = (t40 | t41);
    t26 = (t5 + 4);
    t44 = (t8 + 4);
    t42 = *((unsigned int *)t5);
    t46 = (~(t42));
    t47 = *((unsigned int *)t26);
    t48 = (~(t47));
    t49 = *((unsigned int *)t8);
    t50 = (~(t49));
    t54 = *((unsigned int *)t44);
    t55 = (~(t54));
    t9 = (t46 & t48);
    t35 = (t50 & t55);
    t56 = (~(t9));
    t57 = (~(t35));
    t58 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t58 & t56);
    t59 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t59 & t57);
    t60 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t60 & t56);
    t61 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t61 & t57);
    goto LAB95;

LAB96:    xsi_set_current_line(126, ng0);

LAB99:    xsi_set_current_line(127, ng0);
    t51 = (t0 + 1528U);
    t52 = *((char **)t51);
    t51 = (t0 + 3048);
    t53 = (t51 + 56U);
    t66 = *((char **)t53);
    memset(t94, 0, 8);
    t67 = (t94 + 4);
    t68 = (t66 + 4);
    t71 = *((unsigned int *)t66);
    t72 = (t71 >> 0);
    *((unsigned int *)t94) = t72;
    t73 = *((unsigned int *)t68);
    t74 = (t73 >> 0);
    *((unsigned int *)t67) = t74;
    t75 = *((unsigned int *)t94);
    *((unsigned int *)t94) = (t75 & 255U);
    t78 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t78 & 255U);
    memset(t62, 0, 8);
    t76 = (t94 + 4);
    t79 = 1;
    t80 = *((unsigned int *)t94);
    t81 = *((unsigned int *)t94);
    t81 = (t81 & 1);
    if (*((unsigned int *)t76) != 0)
        goto LAB100;

LAB101:    t82 = 0;

LAB103:    t83 = (t82 <= 7);
    if (t83 == 1)
        goto LAB104;

LAB105:    t85 = (!(t81));
    *((unsigned int *)t62) = t85;

LAB102:    memset(t113, 0, 8);
    t95 = (t52 + 4);
    t96 = (t62 + 4);
    t88 = *((unsigned int *)t52);
    t89 = *((unsigned int *)t62);
    t90 = (t88 ^ t89);
    t91 = *((unsigned int *)t95);
    t92 = *((unsigned int *)t96);
    t93 = (t91 ^ t92);
    t97 = (t90 | t93);
    t98 = *((unsigned int *)t95);
    t99 = *((unsigned int *)t96);
    t100 = (t98 | t99);
    t101 = (~(t100));
    t105 = (t97 & t101);
    if (t105 != 0)
        goto LAB111;

LAB110:    if (t100 != 0)
        goto LAB112;

LAB113:    t103 = (t113 + 4);
    t106 = *((unsigned int *)t103);
    t107 = (~(t106));
    t108 = *((unsigned int *)t113);
    t109 = (t108 & t107);
    t110 = (t109 != 0);
    if (t110 > 0)
        goto LAB114;

LAB115:
LAB116:    xsi_set_current_line(130, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(132, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    goto LAB98;

LAB100:    t77 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t77) = 1;
    goto LAB102;

LAB104:    if (t79 == 1)
        goto LAB107;

LAB108:    t84 = (t80 & 1);
    t81 = (t81 ^ t84);

LAB109:    t80 = (t80 >> 1);

LAB106:    t82 = (t82 + 1);
    goto LAB103;

LAB107:    t79 = 0;
    goto LAB109;

LAB111:    *((unsigned int *)t113) = 1;
    goto LAB113;

LAB112:    t102 = (t113 + 4);
    *((unsigned int *)t113) = 1;
    *((unsigned int *)t102) = 1;
    goto LAB113;

LAB114:    xsi_set_current_line(128, ng0);
    t104 = ((char*)((ng3)));
    t117 = (t0 + 4168);
    t118 = (t0 + 4168);
    t119 = (t118 + 72U);
    t127 = *((char **)t119);
    t128 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t153, t127, 2, t128, 32, 1);
    t145 = (t153 + 4);
    t111 = *((unsigned int *)t145);
    t36 = (!(t111));
    if (t36 == 1)
        goto LAB117;

LAB118:    goto LAB116;

LAB117:    xsi_vlogvar_assign_value(t117, t104, 0, *((unsigned int *)t153), 1);
    goto LAB118;

LAB122:    t15 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB123;

LAB124:    xsi_set_current_line(148, ng0);
    t17 = ((char*)((ng1)));
    t25 = (t0 + 2888);
    xsi_vlogvar_assign_value(t25, t17, 0, 0, 3);
    goto LAB126;

LAB127:    *((unsigned int *)t8) = 1;
    goto LAB130;

LAB132:    t22 = *((unsigned int *)t8);
    t23 = *((unsigned int *)t15);
    *((unsigned int *)t8) = (t22 | t23);
    t24 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t15);
    *((unsigned int *)t11) = (t24 | t27);
    goto LAB131;

LAB133:    t40 = *((unsigned int *)t43);
    t41 = *((unsigned int *)t25);
    *((unsigned int *)t43) = (t40 | t41);
    t26 = (t5 + 4);
    t44 = (t8 + 4);
    t42 = *((unsigned int *)t5);
    t46 = (~(t42));
    t47 = *((unsigned int *)t26);
    t48 = (~(t47));
    t49 = *((unsigned int *)t8);
    t50 = (~(t49));
    t54 = *((unsigned int *)t44);
    t55 = (~(t54));
    t9 = (t46 & t48);
    t35 = (t50 & t55);
    t56 = (~(t9));
    t57 = (~(t35));
    t58 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t58 & t56);
    t59 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t59 & t57);
    t60 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t60 & t56);
    t61 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t61 & t57);
    goto LAB135;

LAB136:    xsi_set_current_line(150, ng0);

LAB139:    xsi_set_current_line(151, ng0);
    t51 = (t0 + 1528U);
    t52 = *((char **)t51);
    t51 = (t52 + 4);
    t71 = *((unsigned int *)t51);
    t72 = (~(t71));
    t73 = *((unsigned int *)t52);
    t74 = (t73 & t72);
    t75 = (t74 != 0);
    if (t75 > 0)
        goto LAB140;

LAB141:    xsi_set_current_line(154, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4168);
    t5 = (t0 + 4168);
    t6 = (t5 + 72U);
    t7 = *((char **)t6);
    t10 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t8, t7, 2, t10, 32, 1);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t11);
    t9 = (!(t12));
    if (t9 == 1)
        goto LAB145;

LAB146:
LAB142:    xsi_set_current_line(156, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(157, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    goto LAB138;

LAB140:    xsi_set_current_line(152, ng0);
    t53 = ((char*)((ng2)));
    t66 = (t0 + 4168);
    t67 = (t0 + 4168);
    t68 = (t67 + 72U);
    t76 = *((char **)t68);
    t77 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t62, t76, 2, t77, 32, 1);
    t95 = (t62 + 4);
    t78 = *((unsigned int *)t95);
    t36 = (!(t78));
    if (t36 == 1)
        goto LAB143;

LAB144:    goto LAB142;

LAB143:    xsi_vlogvar_assign_value(t66, t53, 0, *((unsigned int *)t62), 1);
    goto LAB144;

LAB145:    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t8), 1);
    goto LAB146;

}

static void Cont_182_3(char *t0)
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

LAB0:    t1 = (t0 + 6152U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(182, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7128);
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
    t18 = (t0 + 7016);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_183_4(char *t0)
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

LAB0:    t1 = (t0 + 6400U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(183, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7192);
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
    t18 = (t0 + 7032);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_184_5(char *t0)
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

LAB0:    t1 = (t0 + 6648U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(184, ng0);
    t2 = (t0 + 4008);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7256);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 3U;
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
    xsi_driver_vfirst_trans(t5, 0, 1);
    t18 = (t0 + 7048);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_00000000003084418875_3260569530_init()
{
	static char *pe[] = {(void *)Always_40_0,(void *)Always_53_1,(void *)Always_76_2,(void *)Cont_182_3,(void *)Cont_183_4,(void *)Cont_184_5};
	xsi_register_didat("work_m_00000000003084418875_3260569530", "isim/Processor_Top_isim_beh.exe.sim/work/m_00000000003084418875_3260569530.didat");
	xsi_register_executes(pe);
}
