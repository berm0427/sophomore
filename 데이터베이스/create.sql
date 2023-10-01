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
  primary key (학번));
  
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
