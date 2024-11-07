#pragma once
#include "Student.h"
#include "Faculty.h"
#include "Equipment.h"
#include "EquipmentPage.h"
#include "BorrowPage.h"
#include "TransactionsPage.h"
#include "ActivityPage.h"

namespace EECEInventoryTrackerv2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MainPage
	/// </summary>
	public ref class MainPage : public System::Windows::Forms::Form
	{
	public:
		Form^ loginPage;
	private: System::Windows::Forms::Button^ transactionsButton;
	public:
		Student^ student;
	private: System::Windows::Forms::Button^ activityButton;

	public:
		Faculty^ faculty;
		MainPage(Student ^studentL, Form^ login) //Needed Code to Transition from Login to MainPage
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			loginPage = login;
			student = studentL;
			studentNameInfo->Text = student->name;
			studentNumberInfo->Text = student->studentNumber;
		}

		MainPage(Faculty^ facultyL, Form^ login) //Needed Code to Transition from Login to MainPage
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			loginPage = login;
			faculty = facultyL;
			studentNameInfo->Text = faculty->name;
			studentNumberInfo->Text = faculty->facultyNumber;
		}


		MainPage() {
			InitializeComponent();
		}
		MainPage(Student^ student) {

			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainPage()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ studentNameInfo;
	private: System::Windows::Forms::Label^ studentNumberInfo;
	private: System::Windows::Forms::Button^ equipmentPageButton;
	private: System::Windows::Forms::Button^ signOutButton;
	private: System::Windows::Forms::Button^ borrowButton;




	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainPage::typeid));
			this->studentNameInfo = (gcnew System::Windows::Forms::Label());
			this->studentNumberInfo = (gcnew System::Windows::Forms::Label());
			this->equipmentPageButton = (gcnew System::Windows::Forms::Button());
			this->signOutButton = (gcnew System::Windows::Forms::Button());
			this->borrowButton = (gcnew System::Windows::Forms::Button());
			this->transactionsButton = (gcnew System::Windows::Forms::Button());
			this->activityButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// studentNameInfo
			// 
			this->studentNameInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->studentNameInfo->BackColor = System::Drawing::Color::Transparent;
			this->studentNameInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->studentNameInfo->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->studentNameInfo->Location = System::Drawing::Point(441, 646);
			this->studentNameInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->studentNameInfo->Name = L"studentNameInfo";
			this->studentNameInfo->Size = System::Drawing::Size(283, 38);
			this->studentNameInfo->TabIndex = 4;
			this->studentNameInfo->Text = L"lol";
			this->studentNameInfo->Click += gcnew System::EventHandler(this, &MainPage::studentInfo_Click);
			// 
			// studentNumberInfo
			// 
			this->studentNumberInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->studentNumberInfo->BackColor = System::Drawing::Color::Transparent;
			this->studentNumberInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->studentNumberInfo->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->studentNumberInfo->Location = System::Drawing::Point(444, 684);
			this->studentNumberInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->studentNumberInfo->Name = L"studentNumberInfo";
			this->studentNumberInfo->Size = System::Drawing::Size(280, 33);
			this->studentNumberInfo->TabIndex = 5;
			this->studentNumberInfo->Text = L"lol";
			// 
			// equipmentPageButton
			// 
			this->equipmentPageButton->BackColor = System::Drawing::Color::Transparent;
			this->equipmentPageButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->equipmentPageButton->FlatAppearance->BorderSize = 0;
			this->equipmentPageButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->equipmentPageButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->equipmentPageButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->equipmentPageButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12));
			this->equipmentPageButton->ForeColor = System::Drawing::Color::White;
			this->equipmentPageButton->Location = System::Drawing::Point(1303, 431);
			this->equipmentPageButton->Margin = System::Windows::Forms::Padding(0);
			this->equipmentPageButton->Name = L"equipmentPageButton";
			this->equipmentPageButton->Size = System::Drawing::Size(193, 59);
			this->equipmentPageButton->TabIndex = 11;
			this->equipmentPageButton->UseVisualStyleBackColor = false;
			this->equipmentPageButton->Click += gcnew System::EventHandler(this, &MainPage::equipmentPageButton_Click);
			// 
			// signOutButton
			// 
			this->signOutButton->BackColor = System::Drawing::Color::Transparent;
			this->signOutButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->signOutButton->FlatAppearance->BorderSize = 0;
			this->signOutButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->signOutButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->signOutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->signOutButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12));
			this->signOutButton->ForeColor = System::Drawing::Color::White;
			this->signOutButton->Location = System::Drawing::Point(1227, 506);
			this->signOutButton->Margin = System::Windows::Forms::Padding(0);
			this->signOutButton->Name = L"signOutButton";
			this->signOutButton->Size = System::Drawing::Size(269, 123);
			this->signOutButton->TabIndex = 12;
			this->signOutButton->UseVisualStyleBackColor = false;
			this->signOutButton->Click += gcnew System::EventHandler(this, &MainPage::signOutButton_Click);
			// 
			// borrowButton
			// 
			this->borrowButton->BackColor = System::Drawing::Color::Transparent;
			this->borrowButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"borrowButton.BackgroundImage")));
			this->borrowButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->borrowButton->FlatAppearance->BorderSize = 0;
			this->borrowButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->borrowButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->borrowButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->borrowButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12));
			this->borrowButton->ForeColor = System::Drawing::Color::White;
			this->borrowButton->Location = System::Drawing::Point(1349, 361);
			this->borrowButton->Margin = System::Windows::Forms::Padding(0);
			this->borrowButton->Name = L"borrowButton";
			this->borrowButton->Size = System::Drawing::Size(147, 59);
			this->borrowButton->TabIndex = 13;
			this->borrowButton->UseVisualStyleBackColor = false;
			this->borrowButton->Click += gcnew System::EventHandler(this, &MainPage::borrowButton_Click);
			// 
			// transactionsButton
			// 
			this->transactionsButton->BackColor = System::Drawing::Color::Transparent;
			this->transactionsButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->transactionsButton->FlatAppearance->BorderSize = 0;
			this->transactionsButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->transactionsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->transactionsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->transactionsButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12));
			this->transactionsButton->ForeColor = System::Drawing::Color::White;
			this->transactionsButton->Location = System::Drawing::Point(1267, 286);
			this->transactionsButton->Margin = System::Windows::Forms::Padding(0);
			this->transactionsButton->Name = L"transactionsButton";
			this->transactionsButton->Size = System::Drawing::Size(229, 59);
			this->transactionsButton->TabIndex = 14;
			this->transactionsButton->UseVisualStyleBackColor = false;
			this->transactionsButton->Click += gcnew System::EventHandler(this, &MainPage::transactionsButton_Click);
			// 
			// activityButton
			// 
			this->activityButton->BackColor = System::Drawing::Color::Transparent;
			this->activityButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->activityButton->FlatAppearance->BorderSize = 0;
			this->activityButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->activityButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->activityButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->activityButton->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->activityButton->ForeColor = System::Drawing::Color::Black;
			this->activityButton->Location = System::Drawing::Point(1280, 208);
			this->activityButton->Margin = System::Windows::Forms::Padding(0);
			this->activityButton->Name = L"activityButton";
			this->activityButton->Size = System::Drawing::Size(216, 59);
			this->activityButton->TabIndex = 15;
			this->activityButton->UseVisualStyleBackColor = false;
			this->activityButton->Click += gcnew System::EventHandler(this, &MainPage::activityButton_Click);
			// 
			// MainPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1495, 752);
			this->Controls->Add(this->activityButton);
			this->Controls->Add(this->transactionsButton);
			this->Controls->Add(this->borrowButton);
			this->Controls->Add(this->signOutButton);
			this->Controls->Add(this->equipmentPageButton);
			this->Controls->Add(this->studentNumberInfo);
			this->Controls->Add(this->studentNameInfo);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MainPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EECE Inventory Tracker";
			this->Load += gcnew System::EventHandler(this, &MainPage::MainPage_Load);
			this->ResumeLayout(false);

		}
	public: Equipment^ equipment = nullptr;

	private: System::Void studentInfo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void studentPhotoInfo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void equipmentPageButton_Click(System::Object^ sender, System::EventArgs^ e) {
	///Code for Transitioning to Equipment Page///
	this->Hide();
	EquipmentPage^ equipmentPage = gcnew EquipmentPage(faculty, this);
	equipmentPage->ShowDialog();
	///////////////////////////////////////////////
}
private: System::Void MainPage_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void signOutButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	loginPage->Show();
}
private: System::Void borrowButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	BorrowPage^ borrowPage = gcnew BorrowPage(student, faculty,this);
	borrowPage->ShowDialog();
}
private: System::Void transactionsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	TransactionsPage^ transactionsPage = gcnew TransactionsPage(faculty,this);
	transactionsPage->ShowDialog();
}
private: System::Void activityButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	ActivityPage^ activityPage = gcnew ActivityPage(faculty, this);
	activityPage->Show();
}
};
}
