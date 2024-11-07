#pragma once
#include "Student.h"
#include "Faculty.h"
#include "MainPage.h"
#include "BorrowPage.h"

namespace EECEInventoryTrackerv2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::IO;

	/// <summary>
	/// Summary for LoginPage
	/// </summary>
	public ref class LoginPage : public System::Windows::Forms::Form
	{
	public:
		LoginPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ studentNumberLogin;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ studentPasswordLogin;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ loginButton;
	private: System::Windows::Forms::Button^ showPassword;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginPage::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->studentNumberLogin = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->studentPasswordLogin = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->showPassword = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(69, 158);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Student No.";
			// 
			// studentNumberLogin
			// 
			this->studentNumberLogin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->studentNumberLogin->Location = System::Drawing::Point(72, 189);
			this->studentNumberLogin->Name = L"studentNumberLogin";
			this->studentNumberLogin->Size = System::Drawing::Size(221, 25);
			this->studentNumberLogin->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 28));
			this->label2->Location = System::Drawing::Point(64, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 57);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Sign in";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->Location = System::Drawing::Point(72, 215);
			this->panel2->Margin = System::Windows::Forms::Padding(0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(220, 2);
			this->panel2->TabIndex = 6;
			// 
			// studentPasswordLogin
			// 
			this->studentPasswordLogin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->studentPasswordLogin->Location = System::Drawing::Point(73, 259);
			this->studentPasswordLogin->Name = L"studentPasswordLogin";
			this->studentPasswordLogin->Size = System::Drawing::Size(221, 25);
			this->studentPasswordLogin->TabIndex = 8;
			this->studentPasswordLogin->UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(70, 228);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(103, 23);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Password";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Location = System::Drawing::Point(74, 285);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(220, 2);
			this->panel1->TabIndex = 9;
			// 
			// loginButton
			// 
			this->loginButton->BackColor = System::Drawing::Color::RoyalBlue;
			this->loginButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->loginButton->FlatAppearance->BorderSize = 0;
			this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12));
			this->loginButton->ForeColor = System::Drawing::Color::White;
			this->loginButton->Location = System::Drawing::Point(74, 325);
			this->loginButton->Margin = System::Windows::Forms::Padding(0);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(110, 48);
			this->loginButton->TabIndex = 10;
			this->loginButton->Text = L"Sign In";
			this->loginButton->UseVisualStyleBackColor = false;
			this->loginButton->Click += gcnew System::EventHandler(this, &LoginPage::loginButton_Click);
			// 
			// showPassword
			// 
			this->showPassword->BackColor = System::Drawing::Color::Transparent;
			this->showPassword->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"showPassword.BackgroundImage")));
			this->showPassword->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->showPassword->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->showPassword->FlatAppearance->BorderSize = 0;
			this->showPassword->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->showPassword->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->showPassword->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->showPassword->ForeColor = System::Drawing::Color::DimGray;
			this->showPassword->Location = System::Drawing::Point(261, 259);
			this->showPassword->Margin = System::Windows::Forms::Padding(0);
			this->showPassword->Name = L"showPassword";
			this->showPassword->Size = System::Drawing::Size(33, 23);
			this->showPassword->TabIndex = 11;
			this->showPassword->UseVisualStyleBackColor = false;
			this->showPassword->Click += gcnew System::EventHandler(this, &LoginPage::showPassword_Click);
			this->showPassword->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &LoginPage::showPassword_MouseClick);
			this->showPassword->MouseLeave += gcnew System::EventHandler(this, &LoginPage::showPassword_MouseLeave);
			this->showPassword->MouseHover += gcnew System::EventHandler(this, &LoginPage::showPassword_MouseHover);
			// 
			// LoginPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(740, 454);
			this->Controls->Add(this->showPassword);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->studentPasswordLogin);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->studentNumberLogin);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"LoginPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EECE Inventory Tracker";
			this->Load += gcnew System::EventHandler(this, &LoginPage::LoginPage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: Student^ student = nullptr; //Global variable which creates an object called student.
	public: Faculty^ faculty = nullptr;

	private: System::Void LoginPage_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ studentNumber = this->studentNumberLogin->Text;
	String^ studentPassword = this->studentPasswordLogin->Text;

	if (studentNumber->Length == 0 || studentPassword->Length == 0) {
		MessageBox::Show("Please enter a valid username and password.", "EECE Inventory Tracker", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	try {
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		// First, check if the user is a student
		String^ sqlQuery = "SELECT * FROM students WHERE studentNumber=@studentNum AND password=@pwd";
		SqlCommand^ command = gcnew SqlCommand(sqlQuery, %sqlConn);
		command->Parameters->AddWithValue("@studentNum", studentNumber);
		command->Parameters->AddWithValue("@pwd", studentPassword);

		SqlDataReader^ reader = command->ExecuteReader();
		if (reader->Read()) {
			// Student login successful
			student = gcnew Student;
			student->id = reader->GetInt32(0);
			student->studentNumber = reader->GetInt32(1).ToString();
			student->name = reader->GetString(2);
			student->program = reader->GetString(3);
			student->contactInfo = reader->GetString(4);
			student->email = reader->GetString(5);
			student->password = reader->GetString(6);
			reader->Close();

			this->Hide();
			BorrowPage^ borrowPage = gcnew BorrowPage(student, faculty, this);  // Pass student object
			studentNumberLogin->Text = "";
			studentPasswordLogin->Text = "";
			borrowPage->Show();

			//LOG THE ACTIVITY
			String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
			SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, %sqlConn);
			activityCMD->Parameters->AddWithValue("@act", "Student Login");
			activityCMD->Parameters->AddWithValue("@id", student->studentNumber);
			activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));
			activityCMD->ExecuteNonQuery();

			return; // Exit here since a valid login was found
		}
		reader->Close();  // Close reader before next query

		// If not a student, check if the user is a faculty member
		sqlQuery = "SELECT * FROM faculty WHERE facultyNumber=@facultyNum AND password=@pwd";
		SqlCommand^ commandFaculty = gcnew SqlCommand(sqlQuery, % sqlConn);
		commandFaculty->Parameters->AddWithValue("@facultyNum", studentNumber);
		commandFaculty->Parameters->AddWithValue("@pwd", studentPassword);

		SqlDataReader^ readerFaculty = commandFaculty->ExecuteReader();
		if (readerFaculty->Read()) {
			// Faculty login successful
			faculty = gcnew Faculty;
			faculty->id = readerFaculty->GetInt32(0);
			faculty->facultyNumber = readerFaculty->GetInt32(1).ToString();
			faculty->name = readerFaculty->GetString(2);
			faculty->program = readerFaculty->GetString(3);
			faculty->contactInfo = readerFaculty->GetString(4);
			faculty->email = readerFaculty->GetString(5);
			faculty->password = readerFaculty->GetString(6);
			readerFaculty->Close();

			this->Hide();
			MainPage^ mainPage = gcnew MainPage(faculty, this);  // Pass faculty object
			studentNumberLogin->Text = "";
			studentPasswordLogin->Text = "";
			mainPage->Show();

			//LOG ACTIVITY FACULTY LOGIN
			String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
			SqlCommand^ activityCMD2 = gcnew SqlCommand(activityQuery, %sqlConn);
			activityCMD2->Parameters->AddWithValue("@act", "Faculty Login");
			activityCMD2->Parameters->AddWithValue("@id", faculty->facultyNumber);
			activityCMD2->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));
			activityCMD2->ExecuteNonQuery();
			return; // Exit here since a valid login was found
		}
		else {
			MessageBox::Show("Username or password is incorrect", "EECE Inventory Tracker", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (SqlException^ ex) {
		MessageBox::Show("SQL Error: " + ex->Message, "EECE Inventory Tracker", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	
}
private: System::Void showPassword_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

}
private: System::Void showPassword_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void showPassword_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	studentPasswordLogin->UseSystemPasswordChar = false;
}
private: System::Void showPassword_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	studentPasswordLogin->UseSystemPasswordChar = true;
}
};
}
