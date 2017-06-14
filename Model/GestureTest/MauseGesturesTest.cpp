
#include <afxres.h>
#include "MauseGestures.h"


LPSTR NazwaKlasy = (LPSTR)"Okno";
MSG Komunikat;

MauseGestures *mg=new MauseGestures(500);

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );

    // REJESTROWANIE KLASY OKNA
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, "Blad rejestracji!", "Blad",
                    MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }

    // TWORZENIE OKNA
    HWND hwnd;

    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "Oto okienko", WS_OVERLAPPEDWINDOW,
                           CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, NULL, NULL, hInstance, NULL );

    if( hwnd == NULL )
    {
        MessageBox( NULL, "Okno nie dziala!", "Blad", MB_ICONEXCLAMATION );
        return 1;
    }

    ShowWindow( hwnd, nCmdShow );
    UpdateWindow( hwnd );

    // Pętla komunikatów
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(hwnd,&p);


        mg->testMauseMovement(p.x,p.y);

        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }
    return Komunikat.wParam;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_LBUTTONDOWN:

            //std::cout<<"LPM"<<"\n";
            mg->m=new MauseGestures::Map(LOWORD(lParam),HIWORD(lParam));
            mg->left_pushed=true;
            mg->gest->push_front(20);
            mg->start = GetTickCount();
            break;

        case WM_LBUTTONUP:
            mg->left_pushed=false;
            if(mg->gest->size()!=0)mg->gest->clear();
            //system("cls");
            mg->start=0;

            break;

        case WM_RBUTTONDOWN:

            //std::cout<<"PPM"<<"\n";
            mg->m=new MauseGestures::Map(LOWORD(lParam),HIWORD(lParam));
            mg->right_pushed=true;
            mg->gest->push_front(30);
            mg->start = GetTickCount();
            break;

        case WM_RBUTTONUP:
            mg->right_pushed=false;
            if(mg->gest->size()!=0)mg->gest->clear();
            mg->start=0;
            break;

        case WM_CLOSE:
            DestroyWindow( hwnd );
            break;

        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;

        default:
            return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}

