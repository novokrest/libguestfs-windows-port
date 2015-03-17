for /l %%x in (1, 1, 10) do (
	echo test-%%x
	LibGuestFS.Windows.NativePort.exe
)