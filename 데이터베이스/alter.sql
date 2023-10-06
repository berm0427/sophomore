use univDB;
alter table 학생
	-- (존재시 활성화)  drop column 등록날짜;
	add	등록날짜 datetime not null default '2023-10-06';
