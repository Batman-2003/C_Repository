@echo off
echo Batch File Execution Started
@echo on
goto %1

:build
    gcc -Wall --pedantic -Wno-pointer-arith src\main.c -o build\app -Iinclude
    @echo off
    goto end

:build-run
    gcc -Wall --pedantic -Wno-pointer-arith src\main.c -o build\app -Iinclude && .\build\app
    @echo off
    goto end

:clean
    DEL /q build\**
    @echo off
    goto end

:end
    echo Batch File Execution Finished
