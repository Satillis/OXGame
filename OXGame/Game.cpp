#include <iostream>
#include <Windows.h>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
	setlocale(0, "");

	srand(time(NULL));

	string gameColors[4]{ "�������","������","������","�����" };

	int menuInput, botStartPos;

	string player1 = "����� 1";
	string player2 = "����� 2";

	char p1Symbol = 'X';
	char p2Symbol = 'O';

	int p1Color = 91;
	int p2Color = 94;

	float stats[3][3]{};

	while (true)
	{
		char gameSymbols[3]{ ' ',p1Symbol,p2Symbol };
		int inGameColor[3]{ 0,p1Color,p2Color };
		string players[3]{ "���������", player1,player2 };

		int grid[3][3]{};

		int cellNum = 1;
		int hodCounter = 9;

		bool setings = 1;
		bool pSetings = 1;

		system("cls");


		cout << " + | ����" << endl;

		cout << "\n 1 | ������ ����" << endl;
		cout << " 2 | ����������" << endl;
		cout << " 3 | ���������" << endl;

		cout << "\n 0 | �����" << endl;

		cout << "\n > | ����: ";

		cin >> menuInput;

		switch (menuInput)
		{

		case 0: return 0;

		case 1:

			while (true)
			{
				hodCounter = 9;
				system("cls");

				if (grid[1][1])
				{
					break;
				}

				cout << " + | �������� ������" << endl;

				cout << "\n 1 | ��������� ����" << endl;
				cout << " 2 | ��� ������" << endl;

				cout << "\n 0 | �����" << endl;

				cout << "\n > | ����: ";

				cin >> menuInput;

				if (!menuInput)
				{
					break;
				}

				switch (menuInput)
				{

				case 1:

					while (hodCounter)
					{


						system("cls");
						cellNum = 1;
						botStartPos = rand() % 9 + 1;

						cout << " + | �������� ������\n\n";

						for (int i = 0; i < 3; i++)
						{
							cout << "\t- - - - - - -\n";
							cout << "\t| ";

							for (int j = 0; j < 3; j++)
							{

								if (!grid[i][j])
								{
									cout << cellNum << " | ";
								}
								else
								{
									cout << "\x1b[" << inGameColor[grid[i][j]] << "m" << gameSymbols[grid[i][j]] << "\x1b[0m | ";
								}

								cellNum++;

							}

							cout << "\n";

						}

						cout << "\t- - - - - - -\n\n";

						cout << "\n > | ����: ";
						cin >> menuInput;

						if (menuInput > 0 && menuInput < 10 && !grid[(menuInput - 1) / 3][(menuInput - 1) % 3])
						{

							grid[(menuInput - 1) / 3][(menuInput - 1) % 3] = 1;
							hodCounter--;

						}
						else
						{
							cout << "\n	�������� ����";
							Sleep(2500);
						}

						if ((grid[(menuInput - 1) / 3][0] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[(menuInput - 1) / 3][1] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[(menuInput - 1) / 3][2] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3]) ||
							(grid[0][(menuInput - 1) % 3] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[1][(menuInput - 1) % 3] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[2][(menuInput - 1) % 3] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3]) ||
							(grid[0][0] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[1][1] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[2][2] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3]) ||
							(grid[0][2] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[1][1] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[2][0] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3]))
						{
							stats[0][1]++;
							stats[int((hodCounter + 1) % 2 + 2 * pow(0, (hodCounter + 1) % 2))][0]++;
							hodCounter = -1;

							cellNum = 1;
							system("cls");
							cout << " + | �������� ������\n\n";

							for (int i = 0; i < 3; i++)
							{
								cout << "\t- - - - - - -\n";
								cout << "\t| ";

								for (int j = 0; j < 3; j++)
								{

									if (!grid[i][j])
									{
										cout << cellNum << " | ";
									}
									else
									{
										cout << "\x1b[" << inGameColor[grid[i][j]] << "m" << gameSymbols[grid[i][j]] << "\x1b[0m | ";
									}

									cellNum++;

								}

								cout << "\n";

							}

							cout << "\t- - - - - - -\n\n";
							cout << "\n������� " << player1;
							Sleep(2500);

							break;
						}

						while (hodCounter)
						{
							if (grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] == 0)
							{
								grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] = 2;
								hodCounter--;
								break;
							}
							else
							{
								botStartPos = ((botStartPos + 1) % 10) + (botStartPos / 10);
							}
						}

						if ((grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] == grid[(botStartPos - 1) / 3][0] && grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] == grid[(botStartPos - 1) / 3][1] && grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] == grid[(botStartPos - 1) / 3][2]) ||
							(grid[0][(botStartPos - 1) % 3] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] && grid[1][(botStartPos - 1) % 3] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] && grid[2][(botStartPos - 1) % 3] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3]) ||
							(grid[0][0] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] && grid[1][1] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] && grid[2][2] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3]) ||
							(grid[0][2] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] && grid[1][1] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3] && grid[2][0] == grid[(botStartPos - 1) / 3][(botStartPos - 1) % 3]))
						{
							stats[1][1]++;
							stats[0][0]++;
							hodCounter = -1;
							cellNum = 1;
							system("cls");
							cout << " + | �������� ������\n\n";

							for (int i = 0; i < 3; i++)
							{
								cout << "\t- - - - - - -\n";
								cout << "\t| ";

								for (int j = 0; j < 3; j++)
								{

									if (!grid[i][j])
									{
										cout << cellNum << " | ";
									}
									else
									{
										cout << "\x1b[" << inGameColor[grid[i][j]] << "m" << gameSymbols[grid[i][j]] << "\x1b[0m | ";
									}

									cellNum++;

								}

								cout << "\n";

							}

							cout << "\t- - - - - - -\n\n";
							cout << "������� ���������";

							Sleep(2500);

							break;
						}

					}

					if (!hodCounter)
					{
						stats[1][2]++;
						stats[0][2]++;

						cellNum = 1;
						system("cls");
						cout << " + | �������� ������\n\n";

						for (int i = 0; i < 3; i++)
						{
							cout << "\t- - - - - - -\n";
							cout << "\t| ";

							for (int j = 0; j < 3; j++)
							{

								if (!grid[i][j])
								{
									cout << cellNum << " | ";
								}
								else
								{
									cout << "\x1b[" << inGameColor[grid[i][j]] << "m" << gameSymbols[grid[i][j]] << "\x1b[0m | ";
								}

								cellNum++;

							}

							cout << "\n";

						}

						cout << "\t- - - - - - -\n\n";

						cout << "\n�����";
						Sleep(2500);
					}

					break;

				case 2:

					while (hodCounter)
					{

						system("cls");
						cellNum = 1;

						cout << " + | �������� ������\n\n";

						for (int i = 0; i < 3; i++)
						{
							cout << "\t- - - - - - -\n";
							cout << "\t| ";

							for (int j = 0; j < 3; j++)
							{

								if (!grid[i][j])
								{
									cout << cellNum << " | ";
								}
								else
								{
									cout << "\x1b[" << inGameColor[grid[i][j]] << "m" << gameSymbols[grid[i][j]] << "\x1b[0m | ";
								}

								cellNum++;

							}

							cout << "\n";

						}

						cout << "\t- - - - - - -\n\n";

						cout << "\n > | ����� ����� \x1b[" << inGameColor[int(hodCounter % 2 + 2 * pow(0, hodCounter % 2))] << "m" << gameSymbols[int(hodCounter % 2 + 2 * pow(0, hodCounter % 2))] << "\x1b[0m: ";
						cin >> menuInput;

						if (menuInput > 0 && menuInput < 10 && !grid[(menuInput - 1) / 3][(menuInput - 1) % 3])
						{

							grid[(menuInput - 1) / 3][(menuInput - 1) % 3] = hodCounter % 2 + 2 * pow(0, hodCounter % 2);
							hodCounter--;

						}
						else
						{
							cout << "\n	�������� ����";
							Sleep(2500);
						}

						if ((grid[(menuInput - 1) / 3][0] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[(menuInput - 1) / 3][1] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[(menuInput - 1) / 3][2] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3]) ||
							(grid[0][(menuInput - 1) % 3] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[1][(menuInput - 1) % 3] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[2][(menuInput - 1) % 3] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3]) ||
							(grid[0][0] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[1][1] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[2][2] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3]) ||
							(grid[0][2] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[1][1] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3] && grid[2][0] == grid[(menuInput - 1) / 3][(menuInput - 1) % 3]))
						{
							stats[int(hodCounter % 2 + 2 * pow(0, hodCounter % 2))][1]++;
							stats[int((hodCounter + 1) % 2 + 2 * pow(0, (hodCounter + 1) % 2))][0]++;


							cellNum = 1;
							system("cls");
							cout << " + | �������� ������\n\n";

							for (int i = 0; i < 3; i++)
							{
								cout << "\t- - - - - - -\n";
								cout << "\t| ";

								for (int j = 0; j < 3; j++)
								{

									if (!grid[i][j])
									{
										cout << cellNum << " | ";
									}
									else
									{
										cout << "\x1b[" << inGameColor[grid[i][j]] << "m" << gameSymbols[grid[i][j]] << "\x1b[0m | ";
									}

									cellNum++;

								}

								cout << "\n";

							}

							cout << "\t- - - - - - -\n\n";

							cout << "\n������� ����� " << players[int((hodCounter + 1) % 2 + 2 * pow(0, (hodCounter + 1) % 2))];
							hodCounter = -1;

							Sleep(2500);

							break;
						}


					}

					if (!hodCounter)
					{
						stats[1][2]++;
						stats[2][2]++;

						cellNum = 1;
						system("cls");
						cout << " + | �������� ������\n\n";

						for (int i = 0; i < 3; i++)
						{
							cout << "\t- - - - - - -\n";
							cout << "\t| ";

							for (int j = 0; j < 3; j++)
							{

								if (!grid[i][j])
								{
									cout << cellNum << " | ";
								}
								else
								{
									cout << "\x1b[" << inGameColor[grid[i][j]] << "m" << gameSymbols[grid[i][j]] << "\x1b[0m | ";
								}

								cellNum++;

							}

							cout << "\n";

						}

						cout << "\t- - - - - - -\n\n";
						cout << "\n�����";
						Sleep(2500);

					}

					break;

				default:

					cout << "\n	�������� ����";
					Sleep(2500);

					break;
				}

			}

			break;

		case 2:

			while (true)
			{

				system("cls");

				cout << " + | ����������" << endl;

				cout << "\t\t\t\x1b[92mW\t\x1b[91mL\t\x1b[94mD\t\x1b[0m|\t����" << endl;

				cout << " 1 | " << player1 << "\t\t" << stats[1][0] << "\t" << stats[1][1] << "\t" << stats[1][2] << "\t|\t" << stats[1][0] * 5 - stats[1][1] * 6 - stats[1][2] * 1.2 << endl;
				cout << " 2 | " << player2 << "\t\t" << stats[2][0] << "\t" << stats[2][1] << "\t" << stats[2][2] << "\t|\t" << stats[2][0] * 5 - stats[2][1] * 6 - stats[2][2] * 1.2 << endl;
				cout << " 3 | " << "���������" << "\t\t" << stats[0][0] << "\t" << stats[0][1] << "\t" << stats[0][2] << "\t|\t" << stats[0][0] * 5 - stats[0][1] * 6 - stats[0][2] * 1.2 << endl;

				cout << "\n 0 | �����" << endl;

				cout << "\n > | ����: ";

				cin >> menuInput;

				if (menuInput)
				{

					cout << "\n	�������� ����";
					Sleep(2500);

				}
				else
				{
					break;
				}

			}

			break;

		case 3:

			while (setings)
			{

				pSetings = 1;

				system("cls");

				cout << " + | ���������" << endl;

				cout << "\n 1 | ����� 1" << endl;
				cout << " 2 | ����� 2" << endl;

				cout << "\n 0 | �����" << endl;

				cout << "\n > | ����: ";

				cin >> menuInput;

				switch (menuInput)
				{

				case 0:

					setings = 0;

					break;

				case 1:

					while (pSetings)
					{

						system("cls");


						cout << " + | ��������� ������ [" << player1 << "]" << endl;

						cout << "\n 1 | ���\t\t: " << player1 << endl;
						cout << " 2 | ������\t\t: " << p1Symbol << endl;
						cout << " 3 | ����\t\t: \x1b[" << p1Color << "m" << gameColors[p1Color % 90 - 1] << "\x1b[0m" << endl;

						cout << "\n 0 | �����" << endl;

						cout << "\n > | ����: ";

						cin >> menuInput;

						switch (menuInput)
						{
						case 0:

							pSetings = 0;

							break;

						case 1:

							cout << "\n > | ������� ����� ���: ";
							cin >> player1;

							break;

						case 2:

							cout << "\n > | ������� ����� ������: ";
							cin >> p1Symbol;

							break;

						case 3:

							system("cls");

							cout << " + | ����" << endl;

							cout << "\n 1 | \x1b[91m�������\x1b[0m" << endl;
							cout << " 2 | \x1b[92m������\x1b[0m" << endl;
							cout << " 3 | \x1b[93m������\x1b[0m" << endl;
							cout << " 4 | \x1b[94m�����\x1b[0m" << endl;

							cout << "\n 0 | �����" << endl;

							cout << "\n > | ����: ";

							cin >> menuInput;

							if (menuInput)
							{
								p1Color = 90 + menuInput;
							}
							else
							{
								cout << "\n	�������� ����. ���� �� ������";
								Sleep(2500);
							}

							break;

						default:

							cout << "\n	�������� ����";
							Sleep(2500);

							break;
						}

					}

					break;

				case 2:

					while (pSetings)
					{

						system("cls");


						cout << " + | ��������� ������ [" << player2 << "]" << endl;

						cout << "\n 1 | ���\t\t: " << player2 << endl;
						cout << " 2 | ������\t\t: " << p2Symbol << endl;
						cout << " 3 | ����\t\t: \x1b[" << p2Color << "m" << gameColors[p2Color % 90 - 1] << "\x1b[0m" << endl;

						cout << "\n 0 | �����" << endl;

						cout << "\n > | ����: ";

						cin >> menuInput;

						switch (menuInput)
						{
						case 0:

							pSetings = 0;

							break;

						case 1:

							cout << "\n > | ������� ����� ���: ";
							cin >> player2;

							break;

						case 2:

							cout << "\n > | ������� ����� ������: ";
							cin >> p2Symbol;

							break;

						case 3:

							system("cls");

							cout << " + | ����" << endl;

							cout << "\n 1 | \x1b[91m�������\x1b[0m" << endl;
							cout << " 2 | \x1b[92m������\x1b[0m" << endl;
							cout << " 3 | \x1b[93m������\x1b[0m" << endl;
							cout << " 4 | \x1b[94m�����\x1b[0m" << endl;

							cout << "\n 0 | �����" << endl;

							cout << "\n > | ����: ";

							cin >> menuInput;

							if (menuInput)
							{
								p2Color = 90 + menuInput;
							}
							else
							{
								cout << "\n	�������� ����. ���� �� ������";
								Sleep(2500);
							}

							break;

						default:

							cout << "\n	�������� ����";
							Sleep(2500);

							break;
						}

					}

					break;

				default:

					cout << "\n	�������� ����";
					Sleep(2500);

					break;
				}

			}

			break;

		default:

			cout << "\n	�������� ����";
			Sleep(2500);

			break;
		}

	}

	return 0;
}