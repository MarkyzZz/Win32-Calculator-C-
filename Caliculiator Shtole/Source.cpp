#include <windows.h>
#include<strstream>
#include "resource1.h"
LPCTSTR ClsName = "BasicApp";
LPCTSTR WndName = "A Simple Window";
/////////////////////////////////////////////////////////////////////Procedure for modeless dialog
INT_PTR CALLBACK Child(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
	
	  std::strstream	characterBuffer;
			char			buffer[256];
			 static double	operand1;
			 static double	operand2;
			static double			result;
			static char		Operator;
			HWND textField = GetDlgItem(hDlg,IDC_EDIT1);
			
    switch (message)
    {
    case WM_INITDIALOG:
        {
		    SetDlgItemText(hDlg,IDC_EDIT1,"");
            return (INT_PTR)TRUE;
        }
    case WM_COMMAND:
		if(HIWORD(wParam)!=BN_CLICKED){
			break;
		}
		 
            switch(LOWORD(wParam)){
				//Digit Buttons
			case IDC_BUTTON17:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"1");
				SetWindowText(textField,buffer);
			break;
			case IDC_BUTTON18:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"2");
				SetWindowText(textField,buffer);
			break;
			case IDC_BUTTON19:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"3");
				SetWindowText(textField,buffer);
			break;
			case IDC_BUTTON20:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"4");
				SetWindowText(textField,buffer);
			break;
			case IDC_BUTTON21:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"5");
				SetWindowText(textField,buffer);
			break;
				case IDC_BUTTON22:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"6");
				SetWindowText(textField,buffer);
			break;
				case IDC_BUTTON23:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"7");
				SetWindowText(textField,buffer);
			break;

			case IDC_BUTTON24:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"8");
				SetWindowText(textField,buffer);
			break;
			case IDC_BUTTON25:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"9");
				SetWindowText(textField,buffer);
			break;
			case IDC_BUTTON26:
				GetWindowText(textField,buffer,strlen(buffer));
				strcat_s(buffer,"0");
				SetWindowText(textField,buffer);
			break;
			//Operations
			case IDC_BUTTON27:
				GetWindowText(textField,buffer,strlen(buffer));
				characterBuffer << buffer;
				characterBuffer >> operand1;
				Operator = '+';
				SetWindowText(textField,"");
			break;
			
			case IDC_BUTTON28:
				GetWindowText(textField,buffer,strlen(buffer));
				characterBuffer << buffer;
				characterBuffer >> operand1;
				Operator = '-';
				SetWindowText(textField,"");
			break;
			case IDC_BUTTON29:
				GetWindowText(textField,buffer,strlen(buffer));
				characterBuffer << buffer;
				characterBuffer >> operand1;
				Operator = '*';
				SetWindowText(textField,"");
			break;
			case IDC_BUTTON30:
				operand1=0;
				operand2=0;
				result=0;
				Operator = ' ';
				SetWindowText(textField,"");
			break;
			case IDC_BUTTON31:
				GetWindowText(textField,buffer,256);
				characterBuffer << buffer;
				characterBuffer >> operand1;
				Operator = '/';
				SetWindowText(textField,"");
			break;

			case IDC_BUTTON33:
				GetWindowText(textField,buffer,256);
			
				characterBuffer << buffer;
				characterBuffer >> operand2;
				characterBuffer.clear();

				switch(Operator){
				case '+':
					result = operand1+operand2;
				break;
				case '-':
					result = operand1-operand2;
				break;
				case '*':
					result = operand1*operand2;
				break;
				case '/':
					if(operand2!=0) result = operand1/operand2;
					else{
						result =0;
						operand1=0;
						operand2=0;
						SetWindowText(textField, "Cannot divide by 0");
					return (INT_PTR) TRUE;					
					}
					
				break;
				}

				
				characterBuffer << result;
				characterBuffer.getline(buffer,256);
				SetWindowText(textField,buffer);
				operand1=0;
				operand2=0;
				result=0;
			break;
				
			}
            return (INT_PTR)TRUE;
        

	case WM_CLOSE:
		SendMessage(hDlg,WM_DESTROY,wParam,lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return FALSE;
    }
    return (INT_PTR)FALSE;
}

/////////////////////////////////////////////////////////////////////

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
               LPSTR lpCmdLine, int nCmdShow)
{
	MSG        Msg;
	HWND modalessHWND = CreateDialog(
		hInstance,
		MAKEINTRESOURCE(IDD_DIALOG1),
		NULL,
		Child
		);
	ShowWindow(modalessHWND, nCmdShow);
	UpdateWindow(modalessHWND);
	
	
	while( GetMessage(&Msg, NULL, 0, 0) )
	{
             TranslateMessage(&Msg);
             DispatchMessage(&Msg);
	}

	return Msg.wParam;
}

/////////////////////////////////////////////////////////////////////