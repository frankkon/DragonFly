/*--create database project_manage_system;*/
/*--use project_manage_system*/

drop table tbl_project_basetab;
create table tbl_project_basetab(
    project_id								char(16)					not null,
    project_name							varchar(255)			not null,
    project_status_id					integer						not null,		/*--0:未开始，1：进行中，2：完成，3：中止，4：暂停*/
    project_step_id						integer						not null,	/*--0:立项评审，1:项目计划，2：需求分析，3：系统设计，4：编码&调测，5：系统测试，6：上线*/
    manager_id								integer,
    plan_start_time						date,
    plan_end_time							date,
    real_start_time						date,
    real_end_time							date,
    budget_money							float,
    budget_manday							float,
    current_money							float,
    current_manday						float,
    total_money								float,
    total_manday							float,
		PRIMARY KEY (project_id)    
);

drop table tbl_project_status;
create table tbl_project_status(
    project_status_id 				integer						not null,
    project_status_name 			varchar(255)			not null,
		PRIMARY KEY (project_status_id)    
);

drop table tbl_project_step;
create table tbl_project_step(
    project_step_id 				integer						not null,
    project_step_name 			varchar(255)			not null,
		PRIMARY KEY (project_step_id)    
);

drop table tbl_project_manager;
create table tbl_project_manager(
    manager_id								integer						not null,
    manager_name							varchar(255)			not null,
    sex												integer						not null,		/*--0:male,1:female*/
    age												integer,
    title											varchar(50),
    mobilephone								char(20),
    innerphone								char(20),
    email											varchar(255),
    qq												varchar(20),
    RTX												varchar(20),
    WeChat										varchar(255),
		PRIMARY KEY (manager_id)      
);

drop table tbl_engineer;
create table tbl_engineer(
    engineer_id								integer						not null,
    engineer_name							integer						not null,
    age												integer,
    skill											integer						not null,	/*--1:java,2:php,3:UI,4:andriod,5:ios,6:test*/
    sex												integer						not null,  /*--0:male,1:female*/
    level											integer						not null,	/*--1-12*/
    mobilephone								char(20),
    innerphone								char(20),
    email											varchar(255),
    qq												varchar(20),
    RTX												varchar(20),
    WeChat										varchar(255),
		PRIMARY KEY (engineer_id)           
);

drop table tbl_task;
create table tbl_task(
    task_id										integer						not null,
    task_desc									varchar(255)			not null,
    plan_start_time						date							not null,
    plan_end_time							date							not null,
    real_start_time						date							not null,
    real_end_time							date							not null,
    project_plan_id						integer						not null,        
		PRIMARY KEY (task_id)    
);

drop table tbl_project_plan;
create table tbl_project_plan(
    project_plan_id						integer						not null,
    project_id								integer						not null,
    manager_id								integer						not null,
    plan_desc									varchar(255)			not null,
    status										integer						not null, /*--0:不被执行，1：正被执行	*/										
		PRIMARY KEY (project_plan_id)    
);

drop table tbl_task_engineer_rela;
create table tbl_task_engineer_rela(
    task_id										integer						not null,
    engineer_id								integer						not null,
		PRIMARY KEY (task_id, engineer_id)    
);
