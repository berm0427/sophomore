-- 데이터 베이스 생성
drop database if exists univDB;
create database if not exists univDB;

-- SQL 명령어를 실행할 대상인 기본 데이터베이스를 univDB로 지정
use univDB;

-- 학생 테이블 생성
create table 학생
( 학번 char(4) not null,
  이름 varchar(20) not NULL,
  주소 varchar(50) NULL default '미정',
  학년 int not null,
  나이 int null,
  성별 char(1) not null,
  휴대폰번호 char(14) null,
  소속학부 varchar(20) null,
  primary key(학번));
  
  -- 과목 테이블 생성
  create table 과목
( 과목번호 char(4) not NULL, 
  이름 varchar(20) not NULL,
  강의실 int not null,
  개설학과 varchar(20) not NULL,
  시수 int not null,
  primary key (과목번호));
  
  -- 수강 테이블 생성  
  create table 수강
( 학번 char(4) not null,
  과목번호 char(4) not NULL,
  신청날짜 date not null,
  중간성적 int not null,
  기말성적 int not null,
  평가학점 char(1) not null,
  primary key (학번, 과목번호),
  foreign key(과목번호) references 과목(과목번호),
  foreign key (학번) references 학생(학번));
  
  -- 학생 테이블 입력
  insert into 학생 
  values ('s001', '김연아', '서울 서초', 4, 23, '여', '010-1111-2222', '컴퓨터');
  insert into 학생 
  values ('s002', '홍길동', DEFAULT, 1, 26, '남', NULL, '통계');
  insert into 학생 
  values ('s003', '이승엽', NULL, 3, 30, '남', NULL, '정보통신');
  insert into 학생 
  values ('s004', '이영애', '경기 분당', 2, NULL, '여', '010-4444-5555', '정보통신');
  insert into 학생 
  values ('s005', '송윤아', '경기 분당', 4, 23, '여', '010-6666-7777', '컴퓨터');
  insert into 학생 
  values ('s006', '홍길동', '서울 종로', 2, 26, '남', '010-8888-9999', '컴퓨터');
  insert into 학생 
  values ('s007', '이은진', '경기 과천', 1, 23, '여', '010-2222-3333', '경영');
  
  -- 과목 테이블 입력
  insert into 과목 
  values ('c001', '데이터베이스', 126, '컴퓨터', 3);
  insert into 과목 
  values ('c002', '정보보호', 137, '정보통신', 3);
  insert into 과목 
  values ('c003', '모바일웹', 128, '컴퓨터', 3);  
  insert into 과목 
  values ('c004', '철학개론', 117, '철학', 2);
  insert into 과목 
  values ('c005', '전공글쓰기', 120, '교양학부', 1);
  
  -- 수강 테이블 입력
  insert into 수강 
  values ('s001', 'c002', '2019-09-03', 93, 98, 'A');
  insert into 수강 
  values ('s004', 'c005', '2019-03-03', 72, 78, 'C');
  insert into 수강 
  values ('s003', 'c002', '2017-09-06', 85, 82, 'B');
  insert into 수강 
  values ('s002', 'c001', '2018-03-10', 31, 50, 'F');
  insert into 수강 
  values ('s001', 'c003', '2019-03-05', 82, 89, 'B');
  insert into 수강 
  values ('s004', 'c003', '2020-09-03', 91, 94, 'A');
  insert into 수강 
  values ('s001', 'c005', '2020-09-03', 74, 79, 'C');  
  insert into 수강 
  values ('s003', 'c001', '2019-03-03', 81, 82, 'B');
  insert into 수강 
  values ('s004', 'c002', '2018-03-05', 92, 95, 'A');
  
  
