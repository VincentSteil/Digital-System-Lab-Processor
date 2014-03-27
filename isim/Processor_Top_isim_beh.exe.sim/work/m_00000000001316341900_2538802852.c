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
static const char *ng0 = "C:/Users/Finn/Downloads/Digital-System-Lab-Processor-beta-mouse-IR-instruction_demo/Digital-System-Lab-Processor-beta-mouse-IR-instruction_demo/IR_Transmitter_SM.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static int ng3[] = {10, 0};
static int ng4[] = {9, 0};
static int ng5[] = {1, 0};
static unsigned int ng6[] = {8U, 0U};
static unsigned int ng7[] = {4U, 0U};
static unsigned int ng8[] = {2U, 0U};
static unsigned int ng9[] = {1U, 0U};
static unsigned int ng10[] = {10U, 0U};
static unsigned int ng11[] = {9U, 0U};
static unsigned int ng12[] = {6U, 0U};
static unsigned int ng13[] = {5U, 0U};



static void Always_50_0(char *t0)
{
    char t13[8];
    char t20[8];
    char t24[8];
    char t38[8];
    char t45[8];
    char t87[8];
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
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t21;
    char *t22;
    char *t23;
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
    char *t37;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    int t69;
    int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;

LAB0:    t1 = (t0 + 6280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 6848);
    *((int *)t2) = 1;
    t3 = (t0 + 6312);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(50, ng0);

LAB5:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 3520U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 5200);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB11;

LAB10:    t12 = (t5 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB11;

LAB14:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB12;

LAB13:    t15 = (t13 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t13);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB15;

LAB16:    xsi_set_current_line(67, ng0);

LAB65:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB17:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(51, ng0);

LAB9:    xsi_set_current_line(52, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 5200);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 4);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB8;

LAB11:    t14 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t13) = 1;
    goto LAB13;

LAB15:    xsi_set_current_line(55, ng0);

LAB18:    xsi_set_current_line(56, ng0);
    t16 = (t0 + 5200);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = ((char*)((ng4)));
    memset(t20, 0, 8);
    t21 = (t18 + 4);
    if (*((unsigned int *)t21) != 0)
        goto LAB20;

LAB19:    t22 = (t19 + 4);
    if (*((unsigned int *)t22) != 0)
        goto LAB20;

LAB23:    if (*((unsigned int *)t18) < *((unsigned int *)t19))
        goto LAB21;

LAB22:    memset(t24, 0, 8);
    t25 = (t20 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t20);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t25) != 0)
        goto LAB26;

LAB27:    t32 = (t24 + 4);
    t33 = *((unsigned int *)t24);
    t34 = *((unsigned int *)t32);
    t35 = (t33 || t34);
    if (t35 > 0)
        goto LAB28;

LAB29:    memcpy(t45, t24, 8);

LAB30:    t77 = (t45 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (t80 & t79);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 5200);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t26 = (t9 ^ t10);
    t27 = (t8 | t26);
    t28 = *((unsigned int *)t11);
    t29 = *((unsigned int *)t12);
    t30 = (t28 | t29);
    t33 = (~(t30));
    t34 = (t27 & t33);
    if (t34 != 0)
        goto LAB45;

LAB42:    if (t30 != 0)
        goto LAB44;

LAB43:    *((unsigned int *)t13) = 1;

LAB45:    memset(t20, 0, 8);
    t15 = (t13 + 4);
    t35 = *((unsigned int *)t15);
    t39 = (~(t35));
    t40 = *((unsigned int *)t13);
    t41 = (t40 & t39);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t15) != 0)
        goto LAB48;

LAB49:    t17 = (t20 + 4);
    t43 = *((unsigned int *)t20);
    t46 = *((unsigned int *)t17);
    t47 = (t43 || t46);
    if (t47 > 0)
        goto LAB50;

LAB51:    memcpy(t38, t20, 8);

LAB52:    t36 = (t38 + 4);
    t91 = *((unsigned int *)t36);
    t92 = (~(t91));
    t93 = *((unsigned int *)t38);
    t94 = (t93 & t92);
    t95 = (t94 != 0);
    if (t95 > 0)
        goto LAB60;

LAB61:    xsi_set_current_line(63, ng0);

LAB64:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 5200);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5200);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);

LAB62:
LAB40:    goto LAB17;

LAB20:    t23 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB22;

LAB21:    *((unsigned int *)t20) = 1;
    goto LAB22;

LAB24:    *((unsigned int *)t24) = 1;
    goto LAB27;

LAB26:    t31 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB27;

LAB28:    t36 = (t0 + 3840U);
    t37 = *((char **)t36);
    memset(t38, 0, 8);
    t36 = (t37 + 4);
    t39 = *((unsigned int *)t36);
    t40 = (~(t39));
    t41 = *((unsigned int *)t37);
    t42 = (t41 & t40);
    t43 = (t42 & 1U);
    if (t43 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t36) != 0)
        goto LAB33;

LAB34:    t46 = *((unsigned int *)t24);
    t47 = *((unsigned int *)t38);
    t48 = (t46 & t47);
    *((unsigned int *)t45) = t48;
    t49 = (t24 + 4);
    t50 = (t38 + 4);
    t51 = (t45 + 4);
    t52 = *((unsigned int *)t49);
    t53 = *((unsigned int *)t50);
    t54 = (t52 | t53);
    *((unsigned int *)t51) = t54;
    t55 = *((unsigned int *)t51);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB35;

LAB36:
LAB37:    goto LAB30;

LAB31:    *((unsigned int *)t38) = 1;
    goto LAB34;

LAB33:    t44 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB34;

LAB35:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t45) = (t57 | t58);
    t59 = (t24 + 4);
    t60 = (t38 + 4);
    t61 = *((unsigned int *)t24);
    t62 = (~(t61));
    t63 = *((unsigned int *)t59);
    t64 = (~(t63));
    t65 = *((unsigned int *)t38);
    t66 = (~(t65));
    t67 = *((unsigned int *)t60);
    t68 = (~(t67));
    t69 = (t62 & t64);
    t70 = (t66 & t68);
    t71 = (~(t69));
    t72 = (~(t70));
    t73 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t73 & t71);
    t74 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t74 & t72);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t71);
    t76 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t76 & t72);
    goto LAB37;

LAB38:    xsi_set_current_line(56, ng0);

LAB41:    xsi_set_current_line(57, ng0);
    t83 = (t0 + 5200);
    t84 = (t83 + 56U);
    t85 = *((char **)t84);
    t86 = ((char*)((ng5)));
    memset(t87, 0, 8);
    xsi_vlog_unsigned_add(t87, 32, t85, 4, t86, 32);
    t88 = (t0 + 5200);
    xsi_vlogvar_assign_value(t88, t87, 0, 0, 4);
    goto LAB40;

LAB44:    t14 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB45;

LAB46:    *((unsigned int *)t20) = 1;
    goto LAB49;

LAB48:    t16 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB49;

LAB50:    t18 = (t0 + 3840U);
    t19 = *((char **)t18);
    memset(t24, 0, 8);
    t18 = (t19 + 4);
    t48 = *((unsigned int *)t18);
    t52 = (~(t48));
    t53 = *((unsigned int *)t19);
    t54 = (t53 & t52);
    t55 = (t54 & 1U);
    if (t55 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t18) != 0)
        goto LAB55;

LAB56:    t56 = *((unsigned int *)t20);
    t57 = *((unsigned int *)t24);
    t58 = (t56 & t57);
    *((unsigned int *)t38) = t58;
    t22 = (t20 + 4);
    t23 = (t24 + 4);
    t25 = (t38 + 4);
    t61 = *((unsigned int *)t22);
    t62 = *((unsigned int *)t23);
    t63 = (t61 | t62);
    *((unsigned int *)t25) = t63;
    t64 = *((unsigned int *)t25);
    t65 = (t64 != 0);
    if (t65 == 1)
        goto LAB57;

LAB58:
LAB59:    goto LAB52;

LAB53:    *((unsigned int *)t24) = 1;
    goto LAB56;

LAB55:    t21 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB56;

LAB57:    t66 = *((unsigned int *)t38);
    t67 = *((unsigned int *)t25);
    *((unsigned int *)t38) = (t66 | t67);
    t31 = (t20 + 4);
    t32 = (t24 + 4);
    t68 = *((unsigned int *)t20);
    t71 = (~(t68));
    t72 = *((unsigned int *)t31);
    t73 = (~(t72));
    t74 = *((unsigned int *)t24);
    t75 = (~(t74));
    t76 = *((unsigned int *)t32);
    t78 = (~(t76));
    t69 = (t71 & t73);
    t70 = (t75 & t78);
    t79 = (~(t69));
    t80 = (~(t70));
    t81 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t81 & t79);
    t82 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t82 & t80);
    t89 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t89 & t79);
    t90 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t90 & t80);
    goto LAB59;

LAB60:    xsi_set_current_line(59, ng0);

LAB63:    xsi_set_current_line(60, ng0);
    t37 = ((char*)((ng5)));
    t44 = (t0 + 5360);
    xsi_vlogvar_assign_value(t44, t37, 0, 0, 1);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 5200);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 32, t4, 4, t5, 32);
    t11 = (t0 + 5200);
    xsi_vlogvar_assign_value(t11, t13, 0, 0, 4);
    goto LAB62;

}

static void Always_77_1(char *t0)
{
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
    char *t13;
    char *t14;
    int t15;
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
    char *t33;
    char *t34;

LAB0:    t1 = (t0 + 6528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 6864);
    *((int *)t2) = 1;
    t3 = (t0 + 6560);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(77, ng0);

LAB5:    xsi_set_current_line(78, ng0);
    t4 = (t0 + 3520U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 5360);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(86, ng0);

LAB14:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 3680U);
    t3 = *((char **)t2);

LAB15:    t2 = ((char*)((ng6)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng7)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng8)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng9)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng10)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng11)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng12)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB28;

LAB29:    t2 = ((char*)((ng13)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB30;

LAB31:    t2 = ((char*)((ng1)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t15 == 1)
        goto LAB32;

LAB33:
LAB35:
LAB34:    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 5040);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 4);

LAB36:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(78, ng0);

LAB9:    xsi_set_current_line(79, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4880);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 4);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5040);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB8;

LAB10:    xsi_set_current_line(82, ng0);

LAB13:    xsi_set_current_line(83, ng0);
    t11 = (t0 + 5040);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 4880);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 4);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5040);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB12;

LAB16:    xsi_set_current_line(88, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 5040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB36;

LAB18:    xsi_set_current_line(89, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 5040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB36;

LAB20:    xsi_set_current_line(90, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 5040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB36;

LAB22:    xsi_set_current_line(91, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t0 + 5040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB36;

LAB24:    xsi_set_current_line(92, ng0);
    t4 = ((char*)((ng10)));
    t5 = (t0 + 5040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB36;

LAB26:    xsi_set_current_line(93, ng0);
    t4 = ((char*)((ng11)));
    t5 = (t0 + 5040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB36;

LAB28:    xsi_set_current_line(94, ng0);
    t4 = ((char*)((ng12)));
    t5 = (t0 + 5040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB36;

LAB30:    xsi_set_current_line(95, ng0);
    t4 = ((char*)((ng13)));
    t5 = (t0 + 5040);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB36;

LAB32:    xsi_set_current_line(96, ng0);
    t4 = (t0 + 5040);
    t5 = (t4 + 56U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng1)));
    memset(t16, 0, 8);
    t13 = (t11 + 4);
    t14 = (t12 + 4);
    t6 = *((unsigned int *)t11);
    t7 = *((unsigned int *)t12);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t13);
    t10 = *((unsigned int *)t14);
    t17 = (t9 ^ t10);
    t18 = (t8 | t17);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB38;

LAB37:    if (t21 != 0)
        goto LAB39;

LAB40:    t25 = (t16 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t16);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB41;

LAB42:    xsi_set_current_line(97, ng0);

LAB45:    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 5040);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 4);

LAB43:    goto LAB36;

LAB38:    *((unsigned int *)t16) = 1;
    goto LAB40;

LAB39:    t24 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB40;

LAB41:    xsi_set_current_line(96, ng0);

LAB44:    xsi_set_current_line(96, ng0);
    t31 = (t0 + 5040);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t0 + 5040);
    xsi_vlogvar_assign_value(t34, t33, 0, 0, 4);
    goto LAB43;

}


extern void work_m_00000000001316341900_2538802852_init()
{
	static char *pe[] = {(void *)Always_50_0,(void *)Always_77_1};
	xsi_register_didat("work_m_00000000001316341900_2538802852", "isim/Processor_Top_isim_beh.exe.sim/work/m_00000000001316341900_2538802852.didat");
	xsi_register_executes(pe);
}
