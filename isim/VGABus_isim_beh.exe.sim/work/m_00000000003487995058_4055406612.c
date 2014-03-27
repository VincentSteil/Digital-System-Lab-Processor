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
static const char *ng0 = "C:/Users/Finn/Downloads/Digital-System-Lab-Processor-beta-mouse-IR-instruction_demo/Digital-System-Lab-Processor-beta-mouse-IR-instruction_demo/Generic_Counter.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};



static void Always_44_0(char *t0)
{
    char t13[8];
    char t38[8];
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
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;

LAB0:    t1 = (t0 + 3600U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 4664);
    *((int *)t2) = 1;
    t3 = (t0 + 3632);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(44, ng0);

LAB5:    xsi_set_current_line(45, ng0);
    t4 = (t0 + 1640U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(47, ng0);

LAB9:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB10;

LAB11:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(46, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 10, 0LL);
    goto LAB8;

LAB10:    xsi_set_current_line(48, ng0);

LAB13:    xsi_set_current_line(49, ng0);
    t4 = (t0 + 1320U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
    memset(t13, 0, 8);
    t11 = (t5 + 4);
    t12 = (t4 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t4);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t12);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t11);
    t22 = *((unsigned int *)t12);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB17;

LAB14:    if (t23 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t13) = 1;

LAB17:    t27 = (t13 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t13);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(56, ng0);

LAB30:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB34;

LAB31:    if (t18 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t13) = 1;

LAB34:    t27 = (t13 + 4);
    t21 = *((unsigned int *)t27);
    t22 = (~(t21));
    t23 = *((unsigned int *)t13);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB35;

LAB36:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_minus(t13, 32, t4, 10, t5, 32);
    t11 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 10, 0LL);

LAB37:
LAB20:    goto LAB12;

LAB16:    t26 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(49, ng0);

LAB21:    xsi_set_current_line(50, ng0);
    t33 = (t0 + 2520);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = (t0 + 608);
    t37 = *((char **)t36);
    memset(t38, 0, 8);
    t36 = (t35 + 4);
    t39 = (t37 + 4);
    t40 = *((unsigned int *)t35);
    t41 = *((unsigned int *)t37);
    t42 = (t40 ^ t41);
    t43 = *((unsigned int *)t36);
    t44 = *((unsigned int *)t39);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t47 = *((unsigned int *)t36);
    t48 = *((unsigned int *)t39);
    t49 = (t47 | t48);
    t50 = (~(t49));
    t51 = (t46 & t50);
    if (t51 != 0)
        goto LAB25;

LAB22:    if (t49 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t38) = 1;

LAB25:    t53 = (t38 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t38);
    t57 = (t56 & t55);
    t58 = (t57 != 0);
    if (t58 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 32, t4, 10, t5, 32);
    t11 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 10, 0LL);

LAB28:    goto LAB20;

LAB24:    t52 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(50, ng0);

LAB29:    xsi_set_current_line(51, ng0);
    t59 = ((char*)((ng1)));
    t60 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t60, t59, 0, 0, 10, 0LL);
    goto LAB28;

LAB33:    t26 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB34;

LAB35:    xsi_set_current_line(57, ng0);

LAB38:    xsi_set_current_line(58, ng0);
    t33 = (t0 + 608);
    t34 = *((char **)t33);
    t33 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t33, t34, 0, 0, 10, 0LL);
    goto LAB37;

}

static void Always_69_1(char *t0)
{
    char t13[8];
    char t28[8];
    char t44[8];
    char t59[8];
    char t67[8];
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
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
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
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    int t91;
    int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    char *t106;

LAB0:    t1 = (t0 + 3848U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 4680);
    *((int *)t2) = 1;
    t3 = (t0 + 3880);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(69, ng0);

LAB5:    xsi_set_current_line(70, ng0);
    t4 = (t0 + 1640U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(72, ng0);

LAB9:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t13, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t2);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB13;

LAB10:    if (t18 != 0)
        goto LAB12;

LAB11:    *((unsigned int *)t13) = 1;

LAB13:    t12 = (t13 + 4);
    t21 = *((unsigned int *)t12);
    t22 = (~(t21));
    t23 = *((unsigned int *)t13);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(79, ng0);

LAB39:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t2) != 0)
        goto LAB42;

LAB43:    t5 = (t13 + 4);
    t14 = *((unsigned int *)t13);
    t15 = *((unsigned int *)t5);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB44;

LAB45:    memcpy(t59, t13, 8);

LAB46:    t66 = (t59 + 4);
    t78 = *((unsigned int *)t66);
    t79 = (~(t78));
    t80 = *((unsigned int *)t59);
    t83 = (t80 & t79);
    t84 = (t83 != 0);
    if (t84 > 0)
        goto LAB58;

LAB59:    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB60:
LAB16:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(71, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    goto LAB8;

LAB12:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB13;

LAB14:    xsi_set_current_line(73, ng0);

LAB17:    xsi_set_current_line(74, ng0);
    t26 = (t0 + 1800U);
    t27 = *((char **)t26);
    memset(t28, 0, 8);
    t26 = (t27 + 4);
    t29 = *((unsigned int *)t26);
    t30 = (~(t29));
    t31 = *((unsigned int *)t27);
    t32 = (t31 & t30);
    t33 = (t32 & 1U);
    if (t33 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t26) != 0)
        goto LAB20;

LAB21:    t35 = (t28 + 4);
    t36 = *((unsigned int *)t28);
    t37 = *((unsigned int *)t35);
    t38 = (t36 || t37);
    if (t38 > 0)
        goto LAB22;

LAB23:    memcpy(t67, t28, 8);

LAB24:    t99 = (t67 + 4);
    t100 = *((unsigned int *)t99);
    t101 = (~(t100));
    t102 = *((unsigned int *)t67);
    t103 = (t102 & t101);
    t104 = (t103 != 0);
    if (t104 > 0)
        goto LAB36;

LAB37:    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB38:    goto LAB16;

LAB18:    *((unsigned int *)t28) = 1;
    goto LAB21;

LAB20:    t34 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB21;

LAB22:    t39 = (t0 + 2520);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    t42 = (t0 + 608);
    t43 = *((char **)t42);
    memset(t44, 0, 8);
    t42 = (t41 + 4);
    t45 = (t43 + 4);
    t46 = *((unsigned int *)t41);
    t47 = *((unsigned int *)t43);
    t48 = (t46 ^ t47);
    t49 = *((unsigned int *)t42);
    t50 = *((unsigned int *)t45);
    t51 = (t49 ^ t50);
    t52 = (t48 | t51);
    t53 = *((unsigned int *)t42);
    t54 = *((unsigned int *)t45);
    t55 = (t53 | t54);
    t56 = (~(t55));
    t57 = (t52 & t56);
    if (t57 != 0)
        goto LAB28;

LAB25:    if (t55 != 0)
        goto LAB27;

LAB26:    *((unsigned int *)t44) = 1;

LAB28:    memset(t59, 0, 8);
    t60 = (t44 + 4);
    t61 = *((unsigned int *)t60);
    t62 = (~(t61));
    t63 = *((unsigned int *)t44);
    t64 = (t63 & t62);
    t65 = (t64 & 1U);
    if (t65 != 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t60) != 0)
        goto LAB31;

LAB32:    t68 = *((unsigned int *)t28);
    t69 = *((unsigned int *)t59);
    t70 = (t68 & t69);
    *((unsigned int *)t67) = t70;
    t71 = (t28 + 4);
    t72 = (t59 + 4);
    t73 = (t67 + 4);
    t74 = *((unsigned int *)t71);
    t75 = *((unsigned int *)t72);
    t76 = (t74 | t75);
    *((unsigned int *)t73) = t76;
    t77 = *((unsigned int *)t73);
    t78 = (t77 != 0);
    if (t78 == 1)
        goto LAB33;

LAB34:
LAB35:    goto LAB24;

LAB27:    t58 = (t44 + 4);
    *((unsigned int *)t44) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB28;

LAB29:    *((unsigned int *)t59) = 1;
    goto LAB32;

LAB31:    t66 = (t59 + 4);
    *((unsigned int *)t59) = 1;
    *((unsigned int *)t66) = 1;
    goto LAB32;

LAB33:    t79 = *((unsigned int *)t67);
    t80 = *((unsigned int *)t73);
    *((unsigned int *)t67) = (t79 | t80);
    t81 = (t28 + 4);
    t82 = (t59 + 4);
    t83 = *((unsigned int *)t28);
    t84 = (~(t83));
    t85 = *((unsigned int *)t81);
    t86 = (~(t85));
    t87 = *((unsigned int *)t59);
    t88 = (~(t87));
    t89 = *((unsigned int *)t82);
    t90 = (~(t89));
    t91 = (t84 & t86);
    t92 = (t88 & t90);
    t93 = (~(t91));
    t94 = (~(t92));
    t95 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t95 & t93);
    t96 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t96 & t94);
    t97 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t97 & t93);
    t98 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t98 & t94);
    goto LAB35;

LAB36:    xsi_set_current_line(75, ng0);
    t105 = ((char*)((ng2)));
    t106 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t106, t105, 0, 0, 1, 0LL);
    goto LAB38;

LAB40:    *((unsigned int *)t13) = 1;
    goto LAB43;

LAB42:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB43;

LAB44:    t11 = (t0 + 2520);
    t12 = (t11 + 56U);
    t26 = *((char **)t12);
    t27 = ((char*)((ng1)));
    memset(t28, 0, 8);
    t34 = (t26 + 4);
    t35 = (t27 + 4);
    t17 = *((unsigned int *)t26);
    t18 = *((unsigned int *)t27);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t34);
    t21 = *((unsigned int *)t35);
    t22 = (t20 ^ t21);
    t23 = (t19 | t22);
    t24 = *((unsigned int *)t34);
    t25 = *((unsigned int *)t35);
    t29 = (t24 | t25);
    t30 = (~(t29));
    t31 = (t23 & t30);
    if (t31 != 0)
        goto LAB50;

LAB47:    if (t29 != 0)
        goto LAB49;

LAB48:    *((unsigned int *)t28) = 1;

LAB50:    memset(t44, 0, 8);
    t40 = (t28 + 4);
    t32 = *((unsigned int *)t40);
    t33 = (~(t32));
    t36 = *((unsigned int *)t28);
    t37 = (t36 & t33);
    t38 = (t37 & 1U);
    if (t38 != 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t40) != 0)
        goto LAB53;

LAB54:    t46 = *((unsigned int *)t13);
    t47 = *((unsigned int *)t44);
    t48 = (t46 & t47);
    *((unsigned int *)t59) = t48;
    t42 = (t13 + 4);
    t43 = (t44 + 4);
    t45 = (t59 + 4);
    t49 = *((unsigned int *)t42);
    t50 = *((unsigned int *)t43);
    t51 = (t49 | t50);
    *((unsigned int *)t45) = t51;
    t52 = *((unsigned int *)t45);
    t53 = (t52 != 0);
    if (t53 == 1)
        goto LAB55;

LAB56:
LAB57:    goto LAB46;

LAB49:    t39 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB50;

LAB51:    *((unsigned int *)t44) = 1;
    goto LAB54;

LAB53:    t41 = (t44 + 4);
    *((unsigned int *)t44) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB54;

LAB55:    t54 = *((unsigned int *)t59);
    t55 = *((unsigned int *)t45);
    *((unsigned int *)t59) = (t54 | t55);
    t58 = (t13 + 4);
    t60 = (t44 + 4);
    t56 = *((unsigned int *)t13);
    t57 = (~(t56));
    t61 = *((unsigned int *)t58);
    t62 = (~(t61));
    t63 = *((unsigned int *)t44);
    t64 = (~(t63));
    t65 = *((unsigned int *)t60);
    t68 = (~(t65));
    t91 = (t57 & t62);
    t92 = (t64 & t68);
    t69 = (~(t91));
    t70 = (~(t92));
    t74 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t74 & t69);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t70);
    t76 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t76 & t69);
    t77 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t77 & t70);
    goto LAB57;

LAB58:    xsi_set_current_line(81, ng0);
    t71 = ((char*)((ng2)));
    t72 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t72, t71, 0, 0, 1, 0LL);
    goto LAB60;

}

static void Cont_89_2(char *t0)
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

LAB0:    t1 = (t0 + 4096U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4792);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1023U;
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
    xsi_driver_vfirst_trans(t5, 0, 9);
    t18 = (t0 + 4696);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_90_3(char *t0)
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

LAB0:    t1 = (t0 + 4344U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 2680);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4856);
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
    t18 = (t0 + 4712);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_00000000003487995058_4055406612_init()
{
	static char *pe[] = {(void *)Always_44_0,(void *)Always_69_1,(void *)Cont_89_2,(void *)Cont_90_3};
	xsi_register_didat("work_m_00000000003487995058_4055406612", "isim/VGABus_isim_beh.exe.sim/work/m_00000000003487995058_4055406612.didat");
	xsi_register_executes(pe);
}
