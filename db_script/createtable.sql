create table tbl_account_info(
    account	                 varchar(16)     not null,
    password                 char(128)       not null,
    password_tips            varchar(128)    ,
    PRIMARY KEY (account)    
);

create table tbl_sys_menu (
    menu_id                  integer         not null, -- 菜单ID
    caption                  varchar(128)    not null, -- 菜单描述
    parent_pos               integer         not null, -- 父节点位置
    node_type                integer         not null, -- 0:弹窗菜单，1：菜单项，2：分隔符
    module                   varchar(20)     ,         -- 对应加载的dll
    PRIMARY KEY (menu_id)    
);

create table tbl_employee (
    employee_id              char(8)         not null, -- 工号
    account                  varchar(16)     not null, -- 账号
    employee_name            varchar(128)    not null, -- 姓名
    sex                      integer         ,         -- 性别
    telephone                varchar(15)     ,         -- 座机
    mobilephone              varchar(15)     ,         -- 手机
    email                    varchar(128)    ,         -- 邮箱
    qq                       varchar(20)     ,         -- QQ号
    weichat                  varchar(128)    ,         -- 微信号
    homephone                varchar(15)     ,         -- 家庭电话
    emergency_contact        varchar(128)    ,         -- 紧急联系人姓名
    emergency_contact_num    varchar(15)     ,         -- 紧急联系人号码
    PRIMARY KEY (employee_id)    
);

create unique index idx_tbl_employee_account on tbl_employee (account);
create index idx_tbl_employee_name on tbl_employee (employee_name);

create table tbl_role (
    role_id                  char(8)         not null, -- 角色编号
    role_name                varchar(128)    not null, -- 角色名称
    parent_id                char(8)         not null, -- 父角色编号
    role_desc                varchar(1024)   ,         -- 角色描述
    PRIMARY KEY (role_id)
);

create table tbl_employee_role (
    employee_id              char(8)         not null, -- 工号
    role_id                  char(8)         not null, -- 角色编号
    PRIMARY KEY (employee_id, role_id)
);

create table tbl_menu_authority (
    role_id                  char(8)         not null, -- 角色编号
    menu_id                  integer         not null, -- 菜单ID
    menu_auth                integer         not null, -- 使用菜单对应功能的权限，0：看不到菜单，1：看到菜单
    add_auth                 integer         not null, -- 新增权限，0：无权限，1：有权限
    modify_auth              integer         not null, -- 修改权限，0：无权限，1：有权限
    delete_auth              integer         not null, -- 删除权限，0：无权限，1：有权限
    query_auth               integer         not null, -- 查询权限，0：无权限，1：有权限
    import_auth              integer         not null, -- 导入权限，0：无权限，1：有权限
    export_auth              integer         not null, -- 导出权限，0：无权限，1：有权限
    print_auth               integer         not null, -- 打印权限，0：无权限，1：有权限
    PRIMARY KEY (role_id, menu_id)
);



