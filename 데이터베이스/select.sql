--

use univDB;
select 이름, 주소 from 학생;

--

use univDB;
select 학번, 이름, 주소, 학년, 나이, 성별, 휴대폰번호, 소속학부 from 학생

--

use univDB;
select distinct 소속학부 from 학생;

--

use univDB;
select 이름, 학년, 소속학부, 휴대폰번호 from 학생 where 학년 >= 2 and 소속학부 = '컴퓨터';

--

use univDB;
select 이름, 학년, 소속학부, 휴대폰번호 from 학생 where (학년 >= 1 and 학년 <= 3) or not (소속학부 = '컴퓨터');

--

use univDB;
select 이름, 학년, 소속학부, 휴대폰번호 from 학생 where (학년 between 1 and 3) or not (소속학부 = '컴퓨터');

--

use univDB;
select 이름, 학년, 소속학부, 휴대폰번호 from 학생 where 소속학부 = '컴퓨터' or 소속학부 = '정보통신' order by 학년 asc; -- asc: 오름차순 (작은거 --> 큰거 순)

--

use univDB;
select * from 학생 order by 학년 asc, 이름 desc; -- asc: 오름차순 ((우선순위가) 작은거 --> (우선순위가) 큰거 순), desc: 내림차순 ((우선순위가) 큰거 --> (우선순위가) 작은거 순)

--
