-- 管理员用户登录信息初始化
insert into tbl_account_info values("admin", "E1F7A8B1B2B057A4A1A71FE6113421B7941B3006A73138326590CEF8DE19FF7831886F72C97B341EF548E04B0FA16680289109927B2BF2D87E460E0B53ADF583", "admin");


-- 菜单初始化
-- 弹出菜单
insert into tbl_sys_menu values(301,   "系统管理(&X)", 0, 0, null);
insert into tbl_sys_menu values(302,   "商品管理(&S)", 0, 0, null);
insert into tbl_sys_menu values(303,   "库存管理(&K)", 0, 0, null);
insert into tbl_sys_menu values(304,   "订单管理(&D)", 0, 0, null);
insert into tbl_sys_menu values(305,   "项目管理(&P)", 0, 0, null);


-- 系统管理菜单项
insert into tbl_sys_menu values(30101, "用户管理",     0, 1, "operator");
insert into tbl_sys_menu values(30102, "角色管理",     0, 1, "role");
insert into tbl_sys_menu values(30103, "权限管理",     0, 1, "auth");

-- 商品管理菜单项
insert into tbl_sys_menu values(30201, "供应商管理",   1, 1, "supplier");
insert into tbl_sys_menu values(30202, "商品管理",     1, 1, "product");
insert into tbl_sys_menu values(30203, "商品组合管理", 1, 1, "prodgroup");

-- 库存管理菜单项
insert into tbl_sys_menu values(30301, "入库管理",     2, 1, "purchase");
insert into tbl_sys_menu values(30302, "入库单管理",   2, 1, "purchaselist");

-- 订单管理菜单项
insert into tbl_sys_menu values(30401, "售货管理",     3, 1, "order");
insert into tbl_sys_menu values(30402, "售货单管理",   3, 1, "orderlist");

-- 项目管理菜单项
insert into tbl_sys_menu values(30501, "项目管理",     4, 1, "project");
insert into tbl_sys_menu values(30502, "资源管理",     4, 1, "resource");
insert into tbl_sys_menu values(30503, "项目资源配置", 4, 1, "resofproj");
insert into tbl_sys_menu values(30504, "工时管理",     4, 1, "worktime");
insert into tbl_sys_menu values(30505, "项目成本表",         4, 1, "projcostreport");
insert into tbl_sys_menu values(30506, "项目资源使用表",     4, 1, "projresreport");


