# 配置生成任务
终端-》配置生成任务
1. 配置生成任务，在终端输入以下命令：
C/C++: cl.exe 生成活动文件编译器: cl.exe

参考在命令行上编译本机 C++ 程序
https://learn.microsoft.com/zh-cn/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-170

https://learn.microsoft.com/en-us/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-170

task.json配置文件的编译选项
https://learn.microsoft.com/zh-cn/cpp/build/reference/compiler-options-listed-by-category?view=msvc-170

2.打开Developer Command Prompt for VS,验证cl.exe命令

VS 2017的开发人员命令提示符
Developer Command Prompt for VS2017
https://code.visualstudio.com/docs/cpp/config-msvc


mkdir projects
cd projects
mkdir helloworld
cd helloworld
code .
The "code ." command opens VS Code in the current working folder, which becomes your "workspace". As you go through the tutorial, you will see three files created in a .vscode folder in the workspace:

tasks.json (build instructions)
launch.json (debugger settings)
c_cpp_properties.json (compiler path and IntelliSense settings)
 上面为在Developer Command Prompt for VS2017命令窗口下打开的VS Code  通过code .命令


 下面为不在developer-command-prompt窗口下方法
 https://code.visualstudio.com/docs/cpp/config-msvc#_run-vs-code-outside-the-developer-command-prompt
 修改tasks.json如下：VsDevCmd.bat根据你安装的VS版本修改
 `
 {
  "version": "2.0.0",
  "windows": {
    "options": {
      "shell": {
        "executable": "cmd.exe",
        "args": [
          "/C",
          // The path to VsDevCmd.bat depends on the version of Visual Studio you have installed.
          "\"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/Tools/VsDevCmd.bat\"",
          "&&"
        ]
      }
    }
  },
  "tasks": [
    {
      "type": "shell",
      "label": "cl.exe build active file",
      "command": "cl.exe",
      "args": [
        "/Zi",
        "/EHsc",
        "/Fe:",
        "${fileDirname}\\${fileBasenameNoExtension}.exe",
        "${file}"
      ],
      "problemMatcher": ["$msCompile"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}

 `

 方法3：
 运行命令：  dir "\VsDevCmd*" /s
 把下面想要的路径放到环境变量path中，
 例如：
 C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools
下面为对应命令的执行结果

 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>dir "\VsDevCmd*" /s
 驱动器 C 中的卷是 Windows
 卷的序列号是 E4C0-DCEE

 C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools 的目录

2023/05/17  14:53    <DIR>          vsdevcmd
2025/03/05  18:37            11,526 VsDevCmd.bat
               1 个文件         11,526 字节

 C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd\core 的目录

2025/03/05  18:37             4,066 vsdevcmd_end.bat
2025/03/05  18:37             4,048 vsdevcmd_start.bat
               2 个文件          8,114 字节

 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools 的目录

2023/03/01  16:52    <DIR>          vsdevcmd
2023/03/01  16:52            10,009 VsDevCmd.bat
               1 个文件         10,009 字节

 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\vsdevcmd\core 的目录

2023/03/01  16:52             3,878 vsdevcmd_end.bat
2023/03/01  16:52             3,941 vsdevcmd_start.bat
               2 个文件          7,819 字节

 C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools 的目录

2023/03/01  18:17    <DIR>          vsdevcmd
2023/03/01  18:17            11,073 VsDevCmd.bat
               1 个文件         11,073 字节

 C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\vsdevcmd\core 的目录

2023/03/01  18:17             3,878 vsdevcmd_end.bat
2023/03/01  18:17             3,941 vsdevcmd_start.bat
               2 个文件          7,819 字节