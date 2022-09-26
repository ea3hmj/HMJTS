@rem 
@echo ===================================================
@echo Instalacion astroserver con los ficheros necesarios
@rem  15122021
@echo off
set mypath=%cd%\
rem  cd \
rem creamos astroserver
IF NOT EXIST "\astroserver\" (
	mkdir \astroserver
)
rem creamos install
IF NOT EXIST "\astroserver\install\" (
 	mkdir \astroserver\install
)
IF EXIST "\astroserver\install\install.bat" (
	del \astroserver\install\install.bat
)
copy %mypath%install.bat \astroserver\install\install.bat


cd \astroserver
set astroserverpath=%cd%\
rem creamos bin
IF NOT EXIST ".\bin\" (
	mkdir bin
)
rem cd bin
IF NOT EXIST "\astroserver\install\wget.exe" (
 	copy %mypath%wget.exe \astroserver\install\wget.exe
)
IF NOT EXIST "\astroserver\install\Shortcut.exe" (
 	copy %mypath%wget.exe \astroserver\install\Shortcut.exe
)
cd bin
IF NOT EXIST "astroserver.exe" (
	..\install\wget http://ea3hmj.net/download/astroserver/astroserver.exe astroserver.exe
	..\install\wget http://ea3hmj.net/download/astroserver/astroserver.ico astroserver.ico
	..\install\wget http://ea3hmj.net/download/astroserver/path.txt path.txt
	
rem 	..\install\wget http://ea3hmj.net/download/astroserver/Astroserver.lnk Astroserver.lnk
rem 	copy Astroserver.lnk %systemdrive%%homepath%\Desktop\Astroserver.lnk

	..\install\Shortcut.exe /f:"%USERPROFILE%\Desktop\astroserver.lnk" /a:c /t:%astroserverpath%bin\astroserver.exe /i:%astroserverpath%bin\astroserver.ico

echo [InternetShortcut] >> "%AllUsersProfile%\desktop\astroserver.lnk"
echo URL="%astroserverpath%bin\astroserver.exe" >> "%AllUsersProfile%\desktop\astroserver.lnk"
echo IconFile=%astroserverpath%bin\astroserver.ico >> "%AllUsersProfile%\desktop\astroserver.lnk"
rem echo IconIndex=20 >> "%AllUsersProfile%\desktop\NOTEPAD.url"
)

rem creamos estructura de los kernels
cd ..
IF NOT EXIST "\astroserver\kernels\" (
	mkdir \astroserver\kernels
	cd \astroserver\kernels
	mkdir ck
	mkdir ek
	mkdir fk
	mkdir ik
	mkdir lsk
	mkdir pck
	mkdir sclk
	mkdir spk
	mkdir bodys
	mkdir Scripts
)
cd \astroserver\kernels\bodys
rem cd bodys

IF NOT EXIST "sondas.dat" (
	..\..\install\wget http://ea3hmj.net/download/astroserver/bodys.dat bodys.dat
	..\..\install\wget http://ea3hmj.net/download/astroserver/sondas.dat sondas.dat
	..\..\install\wget http://ea3hmj.net/download/astroserver/sondasManuales.dat sondasManuales.dat
	..\..\install\wget http://ea3hmj.net/download/astroserver/stations.dat stations.dat
rem 	..\..\install\wget http://ea3hmj.net/download/astroserver/dsn.dat dsn.dat
rem 	..\..\install\wget http://ea3hmj.net/download/astroserver/catalog.dat catalog.dat
rem 	..\..\install\wget http://ea3hmj.net/download/astroserver/leo.dat leo.dat
)
cd ..

cd fk
IF NOT EXIST "usr_topo.tf" (
	..\..\install\wget http://ea3hmj.net/download/astroserver/usr_topo.tf usr_topo.tf
)
cd ..\lsk
IF NOT EXIST "latest_leapseconds.tls" (
	..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/lsk/latest_leapseconds.tls latest_leapseconds.tls 
)

cd ..\pck
IF NOT EXIST "earth_latest_high_prec.bpc" (
	..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/earth_latest_high_prec.bpc earth_latest_high_prec.bpc
	..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/pck00010.tpc pck00010.tpc
)
cd ..\spk
IF NOT EXIST "de440.bsp" (
	..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/planets/de440.bsp de440.bsp
	rem ..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/mar097.bsp mar097.bsp
	rem ..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/sat427.bsp sat427.bsp
	rem ..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/ura116.bsp ura116.bsp
	rem ..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/nep095.bsp nep095.bsp
	rem ..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/jup365.bsp jup365.bsp
	rem ..\..\install\wget https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/plu058.bsp plu058.bsp
)
cd ..

cd Scripts
IF NOT EXIST "SondasUpdate.exe" (
	..\..\install\wget http://ea3hmj.net/download/astroserver/SondasUpdate.exe SondasUpdate.exe
	..\..\install\wget http://naif.jpl.nasa.gov/pub/naif/utilities/PC_Windows_32bit/brief.exe brief.exe
	SondasUpdate
)
cd ..

rem creamos el kernel del usuario
IF NOT EXIST ".\make_bsp\" (
	mkdir make_bsp
)
cd make_bsp
IF NOT EXIST "makekernel.exe" (
	..\..\install\wget http://ea3hmj.net/download/astroserver/MakeKernel.exe makekernel.exe
	..\..\install\wget http://naif.jpl.nasa.gov/pub/naif/utilities/PC_Windows_32bit/pinpoint.exe pinpoint.exe
	makekernel
)

cd ..

cd ..
rem creamos astroserver
cd \astroserver\bin
IF NOT EXIST "astrotracker.exe" (
	..\install\wget http://ea3hmj.net/download/astroserver/AstroTracker.exe astrotracker.exe
	..\install\wget http://ea3hmj.net/download/astroserver/AstroClient.dll AstroClient.dll
)
cd ..
cd bin
rem astroserver
@echo.
@echo ===================================================
@echo =                                                 =
@echo =        Astroserver instalado correctamente      =
@echo =                                                 =
@echo =         Ejecutar enlace en el escritorio        =
@echo =                                                 =
@echo =  'astroserver' para activar servidor de objetos =
@echo =                                                 =
@echo ===================================================
@echo =                                                 =
@echo = Run 'astrotracker' en \astroserver\bin          =
@echo =                                                 =
@echo =    para verificar funcionamiento servidor       =
@echo =                                                 =
@echo ===================================================
rem @pause Pulsa una tecla para continuar







