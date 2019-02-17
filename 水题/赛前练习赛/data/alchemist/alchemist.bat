@echo off
if "%1"=="" goto loop
copy alchemist%1.in alchemist.in >nul
echo Problem Test
echo Data %1
time<enter
alchemist
time<enter
fc alchemist.out alchemist%1.out
del alchemist.in
del alchemist.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
