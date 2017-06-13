//linia 647 - zmiana sciezki - docelowo do zmiennej originalImage wczytac zdjecie w rozmiarze oryginalnym i wywolac initMainWindow();

#pragma once
#include"optionsForm.h";
#include"SettingsAnnotationForm.h";
#include <msclr\marshal_cppstd.h>
#include <opencv2\core.hpp>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
//#include "MouseEvent.h"
#include <Windows.h>
#include <iostream>
#include<string>
#include <vector>
#include "ZoomOverview.h"//KKK

struct wsp {
	int x;
	int y;
	wsp(int a, int b) { x = a; y = b; }
};

std::vector <std::vector<wsp>> wektorKsztaltow;
std::vector <wsp> wektorTemp;
int count = 0, iwsk, jwsk;
bool isPoli = false, moveStatus = false;
cv::Mat orginalImg;
cv::Mat img;

static void DrawFigure(int x, int y) {

if (count == 0) {
	wektorTemp.push_back(wsp(x, y));
	circle(img, cv::Point(x, y), 3.0, cv::Scalar(255, 0, 0), -1, 8);
}
if (count > 0) {

	if ((abs(wektorTemp[0].x - x) < 8) && (abs(wektorTemp[0].y - y) < 8)) {
		cv::line(img, cv::Point(wektorTemp[count - 1].x, wektorTemp[count - 1].y), cv::Point(wektorTemp[0].x, wektorTemp[0].y), cv::Scalar(255, 0, 0), 1, 8);
		imshow("splash", img);
		wektorKsztaltow.push_back(wektorTemp);//przepisz();
		wektorTemp.clear();
		count = -1;
		isPoli = false;
	}
	else {
		wektorTemp.push_back(wsp(x, y));
		circle(img, cv::Point(wektorTemp[count].x, wektorTemp[count].y), 3.0, cv::Scalar(255, 0, 0), -1, 8);
		cv::line(img, cv::Point(wektorTemp[count - 1].x, wektorTemp[count - 1].y), cv::Point(wektorTemp[count].x, wektorTemp[count].y), cv::Scalar(255, 0, 0), 1, 8);
		imshow("splash", img);
	}
}
count++;
}

static void DrawAll() {

	orginalImg.copyTo(img);
	for (int i = 0; i < wektorKsztaltow.size(); i++) {
		for (int j = 0; j <= wektorKsztaltow[i].size() - 1; j++) {
			if (j == wektorKsztaltow[i].size() - 1) {
				circle(img, cv::Point(wektorKsztaltow[i][j].x, wektorKsztaltow[i][j].y), 3.0, cv::Scalar(255, 0, 0), -1, 8);
				cv::line(img, cv::Point(wektorKsztaltow[i][j].x, wektorKsztaltow[i][j].y), cv::Point(wektorKsztaltow[i][0].x, wektorKsztaltow[i][0].y), cv::Scalar(255, 0, 0), 1, 8);

			}
			else {
				circle(img, cv::Point(wektorKsztaltow[i][j].x, wektorKsztaltow[i][j].y), 3.0, cv::Scalar(255, 0, 0), -1, 8);
				cv::line(img, cv::Point(wektorKsztaltow[i][j].x, wektorKsztaltow[i][j].y), cv::Point(wektorKsztaltow[i][j + 1].x, wektorKsztaltow[i][j + 1].y), cv::Scalar(255, 0, 0), 1, 8);
			}
		}
	}

	cv::imshow("splash", img);
}

static void DeleteAngle(int x, int y) {
	for (int i = 0; i < wektorKsztaltow.size(); i++) {
		if ( (wektorKsztaltow[i].size() == 1)) {
			wektorKsztaltow.erase(wektorKsztaltow.begin() + i);
			DrawAll();
		}
		else {
			for (int j = 0; j < wektorKsztaltow[i].size(); j++) {
				if ((abs(wektorKsztaltow[i][j].x - x) < 3) && (abs(wektorKsztaltow[i][j].y - y) < 3)) {
					wektorKsztaltow[i].erase(wektorKsztaltow[i].begin() + j);
					DrawAll();
				}
			}

		}
	}
	/*for (int i = 0; i < wektorKsztaltow.size(); i++) {
		for (int j = 0; j < wektorKsztaltow[i].size(); j++) {
			std::cout << "x: " << wektorKsztaltow[i][j].x << " y: " << wektorKsztaltow[i][j].y << std::endl;
		}
	}*/
}

static void MovePoint(int x, int y) {
	
}
static void onMouse(int event, int x, int y, int, void*) {
	cv::Mat copy;
	std::cout << "MOUSE 2";

	if (isPoli) {
		switch (event)
		{
		case CV_EVENT_LBUTTONDOWN:
			DrawFigure(x, y);
			break;
		default:
			if (count != 0) {
				img.copyTo(copy);
				if ((abs(wektorTemp[0].x - x) < 8) && (abs(wektorTemp[0].y - y) < 8)) {
					circle(copy, cv::Point(x, y), 10.0, cv::Scalar(255, 0, 0), 0, 8);
				}

				cv::line(copy, cv::Point(wektorTemp[count - 1].x, wektorTemp[count - 1].y), cv::Point(x, y), cv::Scalar(255, 0, 0), 1, 8);
				imshow("splash", copy);
			}
		}
	}
	else {
		if (moveStatus) {
			std::cout << "yolo";
			wektorKsztaltow[iwsk].erase(wektorKsztaltow[iwsk].begin() + jwsk);
			wektorKsztaltow[iwsk].insert(wektorKsztaltow[iwsk].begin() + jwsk, wsp(x, y));
			DrawAll();
		}
		switch (event) {
		case CV_EVENT_LBUTTONDOWN:
			if (event == CV_EVENT_LBUTTONDOWN) {
				for (int i = 0; i < wektorKsztaltow.size(); i++) {
					for (int j = 0; j < wektorKsztaltow[i].size(); j++) {
						if ((abs(wektorKsztaltow[i][j].x - x) < 8) && (abs(wektorKsztaltow[i][j].y - y) < 8)) {
							iwsk = i;
							jwsk = j;						
							moveStatus = true;
						}
					}
				}
			}
			break;
		case CV_EVENT_LBUTTONUP:
			moveStatus = false;
			break;
		case CV_EVENT_RBUTTONDOWN:
			DeleteAngle(x, y);
			break;
		default:
			img.copyTo(copy);
			for (int i = 0; i < wektorKsztaltow.size(); i++) {
				for (int j = 0; j < wektorKsztaltow[i].size(); j++) {
					if ((abs(wektorKsztaltow[i][j].x - x) < 8) && (abs(wektorKsztaltow[i][j].y - y) < 8)) {	
						circle(copy, cv::Point(x, y), 10.0, cv::Scalar(255, 0, 0), 0, 8);
						iwsk = i;
						jwsk = j;
						imshow("splash", copy);
					}
				}
			}
			imshow("splash", copy);
		}
	}
}

static int calculatePoint(int x1, int y1, int x2, int y2, int x) {
	float a = (float)(y1 - y2) / (float)(x1 - x2);
	float b = (float)y1 - (float)a*x1;
	return (a * x + b);
}


static void DivideSectionCalculate(int pos) {
	int points = 20, j = 20;
	int vectorSize = wektorKsztaltow[pos].size() ;///-1 !!!!!!!!!!!
	//std::cout << "   " << vectorSize;
	POINT tabPointUp[50], tabPointDown[50];
	float point = 0;
	float x = 0, y1 = 0, sum = 0, y2 = 0, high = 0;
	
	int up = 0, down = 0;
	int left = wektorKsztaltow[pos][0].x;
	int right = wektorKsztaltow[pos][0].x;
	for (int i = 1; i < vectorSize; i++) {
		if (left > wektorKsztaltow[pos][i].x) {
			left = wektorKsztaltow[pos][i].x;
			up = i;
		}
		else if (right<wektorKsztaltow[pos][i].x) {
			right = wektorKsztaltow[pos][i].x;
		}
	}
	down = up;

	sum = (float)(right - left) / points;
	
	x = left + sum;
	std::cout << "   " << sum << "   " << left << "   " << x;
	//ktory jest najbardziej w lewo
	
	do {

		for(int i = 0; i < vectorSize; i++){
			if (down == 0) {
				if (x > wektorKsztaltow[pos][vectorSize - 1].x) {
					down--;
					if (down == -1) {
						down = vectorSize - 1;
					}
				}
			}
			else if (x > wektorKsztaltow[pos][down - 1].x) {
				down--;
				if (down == -1) {
					down = vectorSize - 1;
				}
			}

			if (x > wektorKsztaltow[pos][up + 1].x) {
				up++;
				if (up == vectorSize-1) {
					up = 0;
				}
			}
		}
		if (down == 0) {
			//y1 = calculatePoint(tab[up][0], tab[up][1], tab[up + 1][0], tab[up + 1][1], x);
			//y2 = calculatePoint(tab[down][0], tab[down][1], tab[countAngle - 1][0], tab[countAngle - 1][1], x);
			y1 = calculatePoint(wektorKsztaltow[pos][up].x, wektorKsztaltow[pos][up].y, wektorKsztaltow[pos][up + 1].x, wektorKsztaltow[pos][up+1].y, x);
			y2 = calculatePoint(wektorKsztaltow[pos][down].x, wektorKsztaltow[pos][down].y, wektorKsztaltow[pos][vectorSize - 1].x, wektorKsztaltow[pos][vectorSize - 1].y, x);
		}
		else if (up == vectorSize-1) {//vektorsize -1
						   //y1 = calculatePoint(tab[up][0], tab[up][1], tab[0][0], tab[0][1], x);
						   //y2 = calculatePoint(tab[down][0], tab[down][1], tab[down - 1][0], tab[down - 1][1], x);
			y1 = calculatePoint(wektorKsztaltow[pos][up].x, wektorKsztaltow[pos][up].y, wektorKsztaltow[pos][0].x, wektorKsztaltow[pos][0].y, x);
			y2 = calculatePoint(wektorKsztaltow[pos][down].x, wektorKsztaltow[pos][down].y, wektorKsztaltow[pos][down - 1].x, wektorKsztaltow[pos][down - 1].y, x);
		}
		else {
			//y1 = calculatePoint(tab[up][0], tab[up][1], tab[up + 1][0], tab[up + 1][1], x);
			//y2 = calculatePoint(tab[down][0], tab[down][1], tab[down - 1][0], tab[down - 1][1], x);
			y1 = calculatePoint(wektorKsztaltow[pos][up].x, wektorKsztaltow[pos][up].y, wektorKsztaltow[pos][up + 1].x, wektorKsztaltow[pos][up+1].y, x);
			y2 = calculatePoint(wektorKsztaltow[pos][down].x, wektorKsztaltow[pos][down].y, wektorKsztaltow[pos][down - 1].x, wektorKsztaltow[pos][down - 1].y, x);
		}

		high = y1 - y2;

		circle(img, cv::Point(x, (2 * high / 3) + y2), 3.0, cv::Scalar(0, 255, 0), -1, 8);
		circle(img, cv::Point(x, (high / 3) + y2), 3.0, cv::Scalar(0, 255, 255), -1, 8);
		tabPointUp[points].x = x;
		tabPointUp[points].y = (2 * high / 3) + y2;
		tabPointDown[points].x = x;
		tabPointDown[points].y = high / 3 + y2;


		x = x + sum;

		
		points--;
	} while (points > 1);


	for (j; j != 2; j--) {

		cv::line(img, cv::Point(tabPointUp[j].x, tabPointUp[j].y), cv::Point(tabPointUp[j - 1].x, tabPointUp[j - 1].y), cv::Scalar(0, 255, 0), 1, 8);
		cv::line(img, cv::Point(tabPointDown[j].x, tabPointDown[j].y), cv::Point(tabPointDown[j - 1].x, tabPointDown[j - 1].y), cv::Scalar(0, 255, 255), 1, 8);
	}
	imshow("splash", img);
}


static void DivideSection() {
	//for (int i = 0; i < 30; i++) {
	//	std::cout << "x: " << tabmemory[i][0] << "  y: " << tabmemory[i][1] << std::endl;
	//}

	/*
	int i = 0;
	do {
	i = madeTab(i);
	DivideSectionCalculate();
	//std::cout << " here";
	i++;
	} while (tabmemory[i][0] != 0 && tabmemory[i + 1][0] != 0);
	*/
	for (int i = 0; i < wektorKsztaltow.size(); i++) {
		DivideSectionCalculate(i);
	}


}



namespace Projekt_PP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		IplImage *cvImage;
		Bitmap ^image;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  MenuStrip;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAnnotaionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveDistributionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveCellDestriToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cellParamsSettingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  annotationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomInToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  overviewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  polyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  divideSectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  referenceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  relativeX0ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  relativeX100ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitHMinsFindCellToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sDACellFinderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  negativeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionWindowsToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAnnotaionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveDistributionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveCellDestriToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveStateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadStateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cellParamsSettingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomInToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->overviewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->annotationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->polyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->divideSectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->referenceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->relativeX0ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->relativeX100ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitHMinsFindCellToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sDACellFinderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->negativeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionWindowsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->MenuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// MenuStrip
			// 
			this->MenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->zoomToolStripMenuItem, this->annotationToolStripMenuItem, this->processToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->MenuStrip->Location = System::Drawing::Point(0, 0);
			this->MenuStrip->Name = L"MenuStrip";
			this->MenuStrip->Size = System::Drawing::Size(448, 24);
			this->MenuStrip->TabIndex = 0;
			this->MenuStrip->Text = L"MenuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->openToolStripMenuItem,
					this->saveAnnotaionToolStripMenuItem, this->saveImageToolStripMenuItem, this->saveDistributionToolStripMenuItem, this->saveCellDestriToolStripMenuItem,
					this->saveAllToolStripMenuItem, this->saveStateToolStripMenuItem, this->loadStateToolStripMenuItem, this->cellParamsSettingToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// saveAnnotaionToolStripMenuItem
			// 
			this->saveAnnotaionToolStripMenuItem->Name = L"saveAnnotaionToolStripMenuItem";
			this->saveAnnotaionToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveAnnotaionToolStripMenuItem->Text = L"Save Annotaion";
			// 
			// saveImageToolStripMenuItem
			// 
			this->saveImageToolStripMenuItem->Name = L"saveImageToolStripMenuItem";
			this->saveImageToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveImageToolStripMenuItem->Text = L"Save Image";
			this->saveImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveImageToolStripMenuItem_Click);
			// 
			// saveDistributionToolStripMenuItem
			// 
			this->saveDistributionToolStripMenuItem->Name = L"saveDistributionToolStripMenuItem";
			this->saveDistributionToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveDistributionToolStripMenuItem->Text = L"Save Distribution";
			// 
			// saveCellDestriToolStripMenuItem
			// 
			this->saveCellDestriToolStripMenuItem->Name = L"saveCellDestriToolStripMenuItem";
			this->saveCellDestriToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveCellDestriToolStripMenuItem->Text = L"Save Cell Destription";
			// 
			// saveAllToolStripMenuItem
			// 
			this->saveAllToolStripMenuItem->Name = L"saveAllToolStripMenuItem";
			this->saveAllToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveAllToolStripMenuItem->Text = L"Save All";
			// 
			// saveStateToolStripMenuItem
			// 
			this->saveStateToolStripMenuItem->Name = L"saveStateToolStripMenuItem";
			this->saveStateToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveStateToolStripMenuItem->Text = L"Save State";
			// 
			// loadStateToolStripMenuItem
			// 
			this->loadStateToolStripMenuItem->Name = L"loadStateToolStripMenuItem";
			this->loadStateToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->loadStateToolStripMenuItem->Text = L"Load State";
			// 
			// cellParamsSettingToolStripMenuItem
			// 
			this->cellParamsSettingToolStripMenuItem->Name = L"cellParamsSettingToolStripMenuItem";
			this->cellParamsSettingToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->cellParamsSettingToolStripMenuItem->Text = L"Cell Params Settings";
			// 
			// zoomToolStripMenuItem
			// 
			this->zoomToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->zoomInToolStripMenuItem,
					this->zoomOutToolStripMenuItem, this->overviewToolStripMenuItem
			});
			this->zoomToolStripMenuItem->Name = L"zoomToolStripMenuItem";
			this->zoomToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->zoomToolStripMenuItem->Text = L"Zoom";
			// 
			// zoomInToolStripMenuItem
			// 
			this->zoomInToolStripMenuItem->Name = L"zoomInToolStripMenuItem";
			this->zoomInToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->zoomInToolStripMenuItem->Text = L"Zoom in";
			this->zoomInToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::zoomInToolStripMenuItem_Click);//KKK
			// 
			// zoomOutToolStripMenuItem
			// 
			this->zoomOutToolStripMenuItem->Name = L"zoomOutToolStripMenuItem";
			this->zoomOutToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->zoomOutToolStripMenuItem->Text = L"Zoom out";
			this->zoomOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::zoomOutToolStripMenuItem_Click);//KKK
			// 
			// overviewToolStripMenuItem
			// 
			this->overviewToolStripMenuItem->Name = L"overviewToolStripMenuItem";
			this->overviewToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->overviewToolStripMenuItem->Text = L"Overview";
			this->overviewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::overviewToolStripMenuItem_Click);//KKK
			// 
			// annotationToolStripMenuItem
			// 
			this->annotationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->polyToolStripMenuItem,
					this->divideSectionToolStripMenuItem, this->referenceToolStripMenuItem, this->relativeX0ToolStripMenuItem, this->relativeX100ToolStripMenuItem,
					this->settingsToolStripMenuItem
			});
			this->annotationToolStripMenuItem->Name = L"annotationToolStripMenuItem";
			this->annotationToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->annotationToolStripMenuItem->Text = L"Annotation";
			// 
			// polyToolStripMenuItem
			// 
			this->polyToolStripMenuItem->Name = L"polyToolStripMenuItem";
			this->polyToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->polyToolStripMenuItem->Text = L"Poly";
			this->polyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::polyToolStripMenuItem_Click);
			// 
			// divideSectionToolStripMenuItem
			// 
			this->divideSectionToolStripMenuItem->Name = L"divideSectionToolStripMenuItem";
			this->divideSectionToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->divideSectionToolStripMenuItem->Text = L"Divide Section";
			this->divideSectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::divideSectionToolStripMenuItem_Click);
			// 
			// referenceToolStripMenuItem
			// 
			this->referenceToolStripMenuItem->Name = L"referenceToolStripMenuItem";
			this->referenceToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->referenceToolStripMenuItem->Text = L"Reference  Brightness";
			// 
			// relativeX0ToolStripMenuItem
			// 
			this->relativeX0ToolStripMenuItem->Name = L"relativeX0ToolStripMenuItem";
			this->relativeX0ToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->relativeX0ToolStripMenuItem->Text = L"Relative X0";
			// 
			// relativeX100ToolStripMenuItem
			// 
			this->relativeX100ToolStripMenuItem->Name = L"relativeX100ToolStripMenuItem";
			this->relativeX100ToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->relativeX100ToolStripMenuItem->Text = L"Relative X100";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->settingsToolStripMenuItem->Text = L"Settings";
			this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::settingsToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->exitHMinsFindCellToolStripMenuItem,
					this->sDACellFinderToolStripMenuItem, this->negativeToolStripMenuItem, this->optionWindowsToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// exitHMinsFindCellToolStripMenuItem
			// 
			this->exitHMinsFindCellToolStripMenuItem->Name = L"exitHMinsFindCellToolStripMenuItem";
			this->exitHMinsFindCellToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->exitHMinsFindCellToolStripMenuItem->Text = L"Exit H-Mins Find Cell";
			// 
			// sDACellFinderToolStripMenuItem
			// 
			this->sDACellFinderToolStripMenuItem->Name = L"sDACellFinderToolStripMenuItem";
			this->sDACellFinderToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->sDACellFinderToolStripMenuItem->Text = L"SDA Cell Finder";
			// 
			// negativeToolStripMenuItem
			// 
			this->negativeToolStripMenuItem->Name = L"negativeToolStripMenuItem";
			this->negativeToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->negativeToolStripMenuItem->Text = L"Negative";
			this->negativeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::negativeToolStripMenuItem_Click);//KKK
			// 
			// optionWindowsToolStripMenuItem
			// 
			this->optionWindowsToolStripMenuItem->Name = L"optionWindowsToolStripMenuItem";
			this->optionWindowsToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->optionWindowsToolStripMenuItem->Text = L"Option Windows";
			this->optionWindowsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::optionWindowsToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->AllowDrop = true;
			this->pictureBox1->Location = System::Drawing::Point(0, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(339, 235);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::pictureBox1_DragDrop);
			this->pictureBox1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::pictureBox1_DragEnter);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(448, 262);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->MenuStrip);
			this->KeyPreview = true;
			this->MainMenuStrip = this->MenuStrip;
			this->Name = L"MainForm";
			this->Text = L"CAS-Cell Annotation Software";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->MenuStrip->ResumeLayout(false);
			this->MenuStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();


			originalImage = cv::imread("C:\\Users\\Klaudia\\Pictures\\mozg.jpg");//KKK
			initMainWindow();//KKK

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		//KKK
		if (e->KeyCode.ToString() == "A") { updateMainWindowCenter(originalImgCurrentXCenter - moveAWSDvalue, originalImgCurrentYCenter); }
		else if (e->KeyCode.ToString() == "W") { updateMainWindowCenter(originalImgCurrentXCenter, originalImgCurrentYCenter - moveAWSDvalue); }
		else if (e->KeyCode.ToString() == "S") { updateMainWindowCenter(originalImgCurrentXCenter, originalImgCurrentYCenter + moveAWSDvalue); }
		else if (e->KeyCode.ToString() == "D") { updateMainWindowCenter(originalImgCurrentXCenter + moveAWSDvalue, originalImgCurrentYCenter); }
		else if (e->KeyCode == Keys::Multiply) { zoomIn(); }
		else if (e->KeyCode == Keys::Subtract) { zoomOut(); };	
		
		if (e->Control)
		{
			//
			//	shortcuts
			//
			if (e->KeyCode.ToString() == "O") MessageBox::Show("Open image test");
			else if (e->KeyCode.ToString() == "S") MessageBox::Show("Save Annotation test");
			else if (e->KeyCode.ToString() == "B") MessageBox::Show("Save State test");
			else if (e->KeyCode.ToString() == "N") MessageBox::Show("Load State test");
			else if (e->KeyCode.ToString() == "P") MessageBox::Show("Poly test");
			else if (e->KeyCode.ToString() == "M") MessageBox::Show("Option window test");
			else if ((e->KeyCode == Keys::NumPad9 || e->KeyCode == Keys::D9) && this->zoomToolStripMenuItem->Enabled == true) MessageBox::Show("Zoom out test");
			else if ((e->KeyCode == Keys::NumPad0 || e->KeyCode == Keys::D0) && this->zoomToolStripMenuItem->Enabled == true) MessageBox::Show("Zoom in test");
		}
	}

	//File
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Image Files|*.BMP;*.JPG;*.PNG|All files (*.*)|*.*";
		openFileDialog1->Title = "Select a File";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			bool loaded = false;

			this->Cursor;

			try {
				// Microsoft provided code : System::String to basic string
				std::string filePath = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);

				//temp = cv::imread(filePath.c_str());




				//Test 2
				cvImage = cvLoadImage(filePath.c_str(), cv::IMREAD_COLOR);	// cvImage to obraz wczytany do zmiennej typu IplImage

				img = cv::cvarrToMat(cvImage);								// img to globalna zmienna reprezentujÂ¹ca obraz jako typ cv::Mat
				loaded = true;
				//cvImage = cvCloneImage(&(IplImage)img);					// konwersja z Mat do IplImage
				
				//dodalem do nowego okna Damian
				img.copyTo(orginalImg);
				cv::namedWindow("splash", CV_WINDOW_AUTOSIZE);
				cv::imshow("splash", img);

				img = cv::cvarrToMat(cvImage);								// img to globalna zmienna reprezentuj¹ca obraz jako typ cv::Mat
				loaded = true;
				//cvImage = cvCloneImage(&(IplImage)img);					// konwersja z Mat do IplImage

			}
			catch (cv::Exception &ex) {
				loaded = false;
			}

			if (!loaded) {
				MessageBox::Show("cvLoadImage error !");
				return;
			}
			else {

				/*	if (cvImage->widthStep % 4) {
				cvImage->widthStep += abs(cvImage->widthStep % 4 - 4);

				}*/
				image = gcnew Bitmap(img.cols, img.rows, img.step, Imaging::PixelFormat::Format24bppRgb, (IntPtr)img.data);
				//image = gcnew Bitmap(cvImage->width, cvImage->height, cvImage->widthStep, Imaging::PixelFormat::Format24bppRgb, (IntPtr)cvImage->imageData);

				pictureBox1->Width = image->Width;
				pictureBox1->Height = image->Height;
				pictureBox1->Image = image;
				this->AutoSize = false;
			}
			/*	DON'T FORGET ABOUT MEMORY DISALLOCATION !!!				// <------------- TO W PRZYPADKU IplImage, NIE cv:Mat !
			if (cvImage != NULL) {
			pin_ptr<IplImage*> p = &cvImage;
			cvReleaseImage(p);
			}
			*/
		}
	}

			 // Save Image button
	private: System::Void saveImageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|PNG Image|*.png|Tiff Image|*.tiff";
		saveFileDialog1->Title = "Select Filename";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			std::string filePath = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);

			if (cvImage != NULL) {
				cvSaveImage(filePath.c_str(), cvImage);
			}
			else {
				MessageBox::Show("Nie wczytaÂ³eÂ obrazu!");
			}

		}
	}

	private: System::Void polyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		isPoli = true;
		/*POINT cursorPosition;
		GetCursorPos(&cursorPosition);
		std::cout << cursorPosition.x << " " << cursorPosition.y << std::endl;

		
		img = cv::imread("splash.png", CV_LOAD_IMAGE_COLOR);
		if (img.empty()) {
			std::cout << "Cannot Open the immage" << std::endl;
		}

		
		cv::namedWindow("splash", CV_WINDOW_AUTOSIZE);
		cv::imshow("splash", img);
		*/
		
		cv::setMouseCallback("splash", onMouse, 0);
		cv::waitKey(0);

	}

			 //About
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("CAS--Cell Annotation Software\nAuthors:\n", "CAS_About");
	}

			 // Show Option Window
	private: System::Void optionWindowsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		// formularze chyba pownny byc jako zmienne klasy
		optionsForm ^ optionForm = gcnew optionsForm(/*parametry--> opcje do ustawienia w form1?*/);
		optionForm->Show();
		//this->Hide();
	}
			 //Settings Annotation --> new form
	private: System::Void settingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		// formularze chyba pownny byc jako zmienne klasy
		SettingsAnnotationForm ^ settingsAnnotationForm = gcnew SettingsAnnotationForm(/*parametry--> opcje do ustawienia w form1?*/);
		settingsAnnotationForm->Show();
		//this->Hide();

	}
	private: System::Void pictureBox1_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
		if (e->Data->GetDataPresent(DataFormats::FileDrop, false) == true) {
			e->Effect = DragDropEffects::All;
		}
	}


	private: System::Void pictureBox1_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {

		array<String^>^ paths = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop));
		for each (String^ path in paths) {
			std::string fileName = msclr::interop::marshal_as<std::string>(System::IO::Path::GetFileNameWithoutExtension(path)->ToLower());
			std::string _path = msclr::interop::marshal_as<std::string>(path->ToLower());
			try {
				cvImage = cvLoadImage(_path.c_str(), cv::IMREAD_COLOR);

				img = cv::cvarrToMat(cvImage);								// img to globalna zmienna reprezentujÂ¹ca obraz jako typ cv::Mat

			}
			catch (cv::Exception e) {
				MessageBox::Show("cvLoadImage error !");
				return;
			}
			image = gcnew Bitmap(img.cols, img.rows, img.step, Imaging::PixelFormat::Format24bppRgb, (IntPtr)img.data);
			pictureBox1->Width = image->Width;
			pictureBox1->Height = image->Height;
			pictureBox1->Image = image;
			this->AutoSize = false;

		}
	}


	private: System::Void divideSectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		DivideSection();
	}



	//KKK
	private: System::Void zoomInToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		zoomIn();
	}

	private: System::Void zoomOutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		zoomOut();
	}

	private: System::Void overviewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (overviewActive) {
			cv::destroyWindow("OverviewWindow");
		}
		else {
			initOverviewWindow();
		}
		overviewActive = !overviewActive;
	}

	private: System::Void negativeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		makeNegative();
	}


	};
}
