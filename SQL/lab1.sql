select * from DEPT11 where DEPTNAME in 'SALES';
commit;
select * from DEPT11 where DEPTADDR in ('CHICAGO', 'NEW YORK');
commit;
select YEAR, MIN(SALVALUE) from SALARY11 GROUP BY YEAR having YEAR = 2009;
commit;
select COUNT(EMPNO) from EMP11 ;
commit;
select  JOBNO, JOBNAME, 
case JOBNAME 
when 'CLERK' then 'WORKER'
when 'DRIVER' then 'WORKER'
else JOBNAME
end as RESULT
from JOB11; 

commit;

select  YEAR, MAX(SALVALUE) as MAX_YEAR_SALARY from SALARY11 GROUP BY YEAR;
commit;
select  YEAR, AVG(SALVALUE) as AVG_YEAR_SALARY from SALARY11 GROUP BY YEAR  having COUNT(MONTH) >= 3;
commit;
select * from  EMP11, CAREER11, SALARY11 ;
commit;
select EMPNAME, MONTH, YEAR, SALVALUE from EMP11 e JOIN  SALARY11 s ON E.EMPNO=S.EMPNO;
commit;
select EMPNAME, JOBNAME, DEPTNAME  
from EMP11 e JOIN CAREER11 c ON e.EMPNO=c.EMPNO 
JOIN DEPT11 d on d.DEPTNO=c.DEPTNO 
JOIN JOB11 j on j.JOBNO=c.JOBNO
ORDER BY EMPNAME;
commit;




select * from (
  select JOBNAME from CAREER left join JOB on CAREER.JOBNO = JOB.JOBNO
)
pivot(
  COUNT(JOBNAME) for JOBNAME in ('PRESIDENT','FINANCIAL DIRECTOR', 'EXECUTIVE DIRECTOR', 'MANAGER', 'CLERK', 'DRIVER','SALESMAN')
);


create or replace view EMPS_INFO11 as (
select JOBNO, JOBNAME, COUNT(JOBNAME) as JOBCOUNT
from CAREER11 join JOB11 using(JOBNO)
group by JOBNAME, JOBNO);

select 
case rn
when 1 THEN JOBNAME
when 2 THEN CAST(JOBCOUNT as CHAR(4))
end emps
from (
select e.JOBNAME, e.JOBCOUNT,
ROW_NUMBER()OVER(PARTITION BY e.JOBNAME order by e.JOBNAME) rn
from EMPS_INFO11 e,
(select * from EMPS_INFO11 where ROWNUM <= 3) t_rows
);