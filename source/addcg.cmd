@echo off
if "" == "%1" echo usage %~0 filename & exit /b
call insertcg %1 > %1.cg
del %1
ren %1.cg %1