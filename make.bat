@echo off
setlocal enabledelayedexpansion

set CWD=%~dp0.
cd /d %CWD%

set LLVM_HOME=%CWD%\llvm-3.3.src
set JNAERATOR_JAR=%CWD%\jnaerator-0.11-shaded.jar
set JNAERATOR_CONF=%CWD%\llvm.jnaerator
java -jar %JNAERATOR_JAR% %JNAERATOR_CONF%
pause
