```bash
pi@raspberrypi:~/workspace/CppLessons/BestPracticeTechniques/3_TheStartup $ gcc ./Ex1_AbnormalEntryPoint.cpp  -nostartfiles -Wl,-e,my_start
/usr/bin/ld: warning: cannot find entry symbol my_start; defaulting to 0000000000000360
```
