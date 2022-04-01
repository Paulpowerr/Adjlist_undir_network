#include "Assistance.h"					// ���������
#include "AdjListDirNetwork.h"		// �ڽӱ�������

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		char c = 'a', e, e1, e2;
		int n = 4, v, v1, v2, w;
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D'};
		int m[4][4] = {
			{infity, 2, 3, 4},
			{2, infity, 5, 6},
			{3, 5, infity, 7},
			{4, 6, 7, infity}
		};
		
		/*int m[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = i; j < 3; j++)
				if (i == j) m[i][j] = infity;
				else m[i][j]= rand() % 10;
		}*/


		

		AdjListDirNetwork<char, int> net(vexs, n);

		for (int v = 0; v < 3; v++)
			for (int u = v; u < 3; u++)
				if (m[v][u] != infity) net.InsertArc(v, u, m[v][u]);

	    while (c != '0')	{
            cout << endl << "1. ���������.";
            cout << endl << "2. ��ʾ������.";
            cout << endl << "3. ȡָ�������ֵ.";
            cout << endl << "4. ����ָ�������ֵ.";
            cout << endl << "5. ɾ������.";
            cout << endl << "6. ���붥��.";
            cout << endl << "7. ɾ����.";
            cout << endl << "8. �����.";
            cout << endl << "9. ����ָ���ߵ�Ȩ.";
			cout << endl << "A. ͳ�ƶ���Ķ�";
			cout << endl << "B. ��ͼ����ͨ������Ŀ";
		    cout << endl << "0. �˳�";
		    cout << endl << "ѡ����(0~9):";
		    cin >> c;
		    switch (c) 		{
			    case '1':
			        net.Clear();
				    break;
			    case '2':
                    if (net.IsEmpty())
                        cout << "��������Ϊ�ա�" << endl;
                    else 
			            net.Display();
				    break;
			    case '3':
			        cout << endl << "���붥����ţ��������Ķ�����Ŵ�0��ʼ��:";
			        cin >> v;
		            net.GetElem(v, e);
		            cout << "���Ϊ" << v << "�Ķ���Ϊ" << e;
			        break;
			    case '4':
			        cout << endl << "���붥����ţ��������Ķ�����Ŵ�0��ʼ��:";
			        cin >> v;
			        cout << endl << "����" << v <<"�Ŷ����ֵ:";
			        cin >> e;
		            net.SetElem(v, e);
			        break;
			    case '5':
			        cout << endl << "���뱻ɾ�������ֵ:";
			        cin >> e;
		            net.DeleteVex(e);
			        break;
			    case '6':
			        cout << endl << "������붥���ֵ:";
			        cin >> e;
		            net.InsertVex(e);
			        break;
			    case '7':
			        cout << endl << "�����뱻ɾ���߹�������������ֵ:";
			        cin >> e1 >> e2;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.DeleteArc(v1, v2);
			        break;
			    case '8':
			        cout << endl << "���������߹�������������ֵ�ͱߵ�Ȩֵ:";
			        cin >> e1 >> e2 >> w;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.InsertArc(v1, v2, w);
			        break;
			    case '9':
			        cout << endl << "���������߹�������������ֵ�ͱߵ�Ȩֵ:";
			        cin >> e1 >> e2 >> w;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.SetWeight(v1, v2, w);
			        break;
				case'A':
					cout << endl << "����Ҫ��ѯ�Ķ���ֵ:";
					cin >> e1;
					v = net.GetOrder(e1);
					cout << "�ö���Ķ�Ϊ:" << net.CountDegree(v)<<endl;
					break;
				case'B':
					cout << "��ͼ����ͨ����Ϊ:" << net.ConnectedComponent() << endl;
					break;

       	      }
         }
	}

	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}
	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

