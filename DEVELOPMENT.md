# Weave2 - Development Notes

notes for upkeep and running `weave2` whilst in development.

<hr>

# Weave2 - Installation guide
## 1. Create the Installation Directory 
Weave2 is installed under "C:\Program Files\Weave2", with the executable stored in a bin subdirectory.

To configure this, open PowerShell and run:
```
New-Item -ItemType Directory -Path "C:Program Files\Weave2\bin" -Force
```
Creating directories under <b>C:\Program Files</b> may require administrator privileges on your device.

Expected directory structure:
```
C:\Program Files\Weave2\
└── bin\
    └── Weave2.exe
```

## 2. Install (or Update) the Compiled Executable
Build the project using <b>CLion</b> or <b>CMake</b>, then locate the resulting `Weave2.exe`.

To copy the compiled executable into the installation directory, open PowerShell (admin) in project root, and run:
```
Copy-Item "<YOUR-BUILD-OUTPUT-DIR>\Weave2.exe" "C:\Program Files\Weave2\bin" -Force
```
For example:
```
Copy-Item "cmake-build-debug-winlibs-ucrt64\Weave2.exe" "C:\Program Files\Weave2\bin" -Force
```

## 3. Configure the Windows PATH Environment Variable
Adding the installation directory to PATH allows Windows to find and run Weave2.exe from any working directory.

<b>NOTE:</b> Add the directory containing the executable, not the executable file itself.

### Using Windows Settings
1. Opens Windows start menu.
2. Search for <b>"Edit the system environment variables"</b>
3. Open <B>System Properties</B> window.
4. Select <B>Environment Variables...</B>
5. Under <B>User Variables</B>, select <B>Path</B> and click <B>Edit</B>.
6. Click <B>New</b> and enter:
    ```angular2html
    C:\Program Files\Weave2\bin
    ```
7. Click <b>OK</b> on each open dialog to save the changes.
8. Close and reopen terminals so they inherit the updated environment.

### Verify the PATH Configuration.
Open PowerShell and run:
```
where.exe Weave2
```
Expected output:
```
C:\Program Files\Weave2\bin\Weave2.exe
```
Then test the application using:
```
Weave2 help
```
The application should display its help output.
<hr>

# Weave2 - Repository Files
TODO
```
%LOCALAPPDATA%\Weave2\repos
```

<hr>

# Weave2 - Documentation (Doxygen)
Generate Doxyfile: 
```
doxygen -g Doxyfile
```
(configure settings within this file to liking)

Generate documentation:
```
doxygen Doxyfile
```

Open docsite in brower:
```
Start-Process .\docs\html\index.html
```

