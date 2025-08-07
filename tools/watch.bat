@debug.exe
@echo;
@echo;

@set /a e = %errorlevel%
@cd tools
@if %e% == 0 (color a) else (color 4)
@echo Debug exited %e%

@pause
@exit %e%