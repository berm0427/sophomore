--

use univDB;
select count(*) from 학생;

--

use univDB;
select count(*) as 학생수1, count(주소) as 학생수2, count(distinct 주소) as 학생수3 from 학생; -- as: 어떤 열을 다른 이름으로 바꿔줌

--

use univDB;
select avg(나이) '여학생 평균나이'  from 학생 where 성별 = '여';

--

use univDB;
select 성별, max(나이) as '최고 나이', min(나이) as '최저 나이' from 학생 group by 성별;

--

use univDB;
select 성별, max(나이) as '최고 나이', min(나이) as '최저 나이' from 학생 group by 성별 order by 성별 asc;

--

use univDB;
select 나이, count(*) as '나이별 학생수' from 학생 where 나이 >= 20 and 나이 < 30 group by 나이;

--

use univDB;
select 학년, count(*) as '학년별 학생수' from 학생 group by 학년 having count(*) >= 2;

--

use univDB;
select 학번, 이름 from 학생 where 이름 like '이__';

--

use univDB;
select 이름, 주소, 학년 from 학생 where 주소 like '%서울%' order by 학년 desc;

--

use univDB;
select 이름, 휴대폰번호 from 학생 where 휴대폰번호 is null;

--

use univDB;
select 이름, 휴대폰번호 from 학생 where 휴대폰번호 is not null;

--

use univDB;
select 학번 from 학생 where 성별 = '여' union select 학번 from 수강 where 평가학점 = 'A'; -- 한 테이블안에 학점과 성별이 동시 종재하지 않기 때문에 or로 안되고 union을 써야한다

--

use univDB;
select 이름 from 학생 where 학번 in ('s001', 's003', 's004');

--

use univDB;
select 이름 from 학생 where 학번 in (select 학번 from 수강 where 과목번호 = 'c002'); 

--

use univDB;
select 이름 from 학생 where 학번 in (select 학번 from 수강 where 과목번호 = (select 과목번호 from 과목 where 이름 = '정보보호')); 

--

use univDB;
select 이름 from 학생 where exists (select * from 수강 where 수강.학번 = 학생.학번 and 과목번호 = 'c002');

--

use univDB;
select * from 학생, 수강;

--

use univDB;
select * from 학생 cross join 수강;

--

use univDB;
select  count(*)  from 학생, 수강 ;

--

use univDB;
select count(*) from 학생 cross join 수강;

--

use univDB;
select * from 학생, 수강 where 학생.학번 = 수강.학번;

--

use univDB;
select * from 학생 join 수강 on 학생.학번 = 수강.학번;

--

use univDB;
select 학생.학번, 이름, 과목번호, 중간성적 + (중간성적 * 0.1) as 변환중간성적 from 학생, 수강 where 학생.학번 = 수강.학번 and 과목번호 = 'c002';

--

use univDB;
select 학생.학번, 이름, 과목번호, 중간성적 + (중간성적 * 0.1) as 변환중간성적 from 학생 join 수강 on 학생.학번 = 수강.학번 where 과목번호 = 'c002';

--

use univDB;
select 학생.학번, 학생.이름, 수강.과목번호 from 학생, 수강, 과목 where 학생.학번 = 수강.학번 and 수강.과목번호 = 과목.과목번호 and 과목.이름='정보보호';

--

use univDB;
select 학생.학번, 학생.이름, 수강.과목번호 from (학생 join 수강 on 학생.학번 = 수강.학번) join 과목 on 수강.과목번호 = 과목.과목번호 where 과목.이름='정보보호';

--

use univDB;
select 이름, 과목번호 from 학생 as S, 수강 E where S.학번 = E.학번 and 과목번호 = 'c002';

--

use univDB;
select 이름, 과목번호 from 학생 as S, 수강 as E where S.학번 = E.학번 and 과목번호 = 'c002';

--

use univDB;
select 학생.학번, 이름, 평가학점 from 학생 left outer join 수강 on 학생.학번 = 수강.학번;

--



