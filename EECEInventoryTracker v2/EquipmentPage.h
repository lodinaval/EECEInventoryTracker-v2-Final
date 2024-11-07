#pragma once
#include "Equipment.h"
#include "Faculty.h"
#using "C:\\Games\\itextsharp.dll"
#using "C:\\Games\\BouncyCastle.Cryptography.dll"
#pragma warning(disable: 4691)

namespace EECEInventoryTrackerv2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::IO;
	using namespace iTextSharp::text;
	using namespace iTextSharp::text::pdf;
	using namespace Org::BouncyCastle::X509;

	/// <summary>
	/// Summary for EquipmentPage
	/// </summary>
	public ref class EquipmentPage : public System::Windows::Forms::Form
	{
	
	public:
		Form^ mainPage; //Store reference to MainPage
		Faculty^ faculty;
		EquipmentPage(Faculty^ facultyL, Form^ mainPageRef) //Needed Code to Transition from MainPage to 
		{
			InitializeComponent();
			faculty = facultyL;
			mainPage = mainPageRef;
			// Add this line in the form's initialization (usually in the constructor or InitializeComponent)
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EquipmentPage()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::DataGridView^ tblEquipment;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ equipmentDescriptionTextBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ equipmentNameTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ equipmentStockCount;
	private: System::Windows::Forms::Button^ addEquipmentButton;

	private: System::Windows::Forms::NumericUpDown^ equipmentStockUpdate;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ equipmentDescriptionUpdate;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ equipmentNameUpdate;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ updateEquipmentButton;
	private: System::Windows::Forms::Button^ deleteEquipmentButton;
	private: System::Windows::Forms::TextBox^ searchEquipmentTextBox;
	private: System::Windows::Forms::Label^ searchEquipmentLabel;
	private: System::Windows::Forms::Button^ equipmentHomeButton;
	private: System::Windows::Forms::Button^ exportEquipmentButton;







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
			this->tblEquipment = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->addEquipmentButton = (gcnew System::Windows::Forms::Button());
			this->equipmentStockCount = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->equipmentDescriptionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->equipmentNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->updateEquipmentButton = (gcnew System::Windows::Forms::Button());
			this->equipmentStockUpdate = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->equipmentDescriptionUpdate = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->equipmentNameUpdate = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->deleteEquipmentButton = (gcnew System::Windows::Forms::Button());
			this->searchEquipmentTextBox = (gcnew System::Windows::Forms::TextBox());
			this->searchEquipmentLabel = (gcnew System::Windows::Forms::Label());
			this->equipmentHomeButton = (gcnew System::Windows::Forms::Button());
			this->exportEquipmentButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblEquipment))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->equipmentStockCount))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->equipmentStockUpdate))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tblEquipment
			// 
			this->tblEquipment->AllowUserToAddRows = false;
			this->tblEquipment->AllowUserToDeleteRows = false;
			this->tblEquipment->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tblEquipment->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->tblEquipment->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tblEquipment->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->tblEquipment->Location = System::Drawing::Point(367, 12);
			this->tblEquipment->Name = L"tblEquipment";
			this->tblEquipment->ReadOnly = true;
			this->tblEquipment->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->tblEquipment->Size = System::Drawing::Size(608, 564);
			this->tblEquipment->TabIndex = 0;
			this->tblEquipment->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentPage::tblEquipment_CellClick);
			this->tblEquipment->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EquipmentPage::tblEquipment_CellContentClick);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 123);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(339, 286);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->addEquipmentButton);
			this->tabPage1->Controls->Add(this->equipmentStockCount);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->equipmentDescriptionTextBox);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->equipmentNameTextBox);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(331, 260);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Add Equipment";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// addEquipmentButton
			// 
			this->addEquipmentButton->Location = System::Drawing::Point(132, 188);
			this->addEquipmentButton->Name = L"addEquipmentButton";
			this->addEquipmentButton->Size = System::Drawing::Size(193, 65);
			this->addEquipmentButton->TabIndex = 6;
			this->addEquipmentButton->Text = L"ADD EQUIPMENT";
			this->addEquipmentButton->UseVisualStyleBackColor = true;
			this->addEquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPage::addEquipmentButton_Click);
			// 
			// equipmentStockCount
			// 
			this->equipmentStockCount->Location = System::Drawing::Point(10, 188);
			this->equipmentStockCount->Name = L"equipmentStockCount";
			this->equipmentStockCount->Size = System::Drawing::Size(110, 20);
			this->equipmentStockCount->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 171);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Equipment Stock";
			// 
			// equipmentDescriptionTextBox
			// 
			this->equipmentDescriptionTextBox->Location = System::Drawing::Point(13, 72);
			this->equipmentDescriptionTextBox->Multiline = true;
			this->equipmentDescriptionTextBox->Name = L"equipmentDescriptionTextBox";
			this->equipmentDescriptionTextBox->Size = System::Drawing::Size(312, 94);
			this->equipmentDescriptionTextBox->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Equipment Description";
			// 
			// equipmentNameTextBox
			// 
			this->equipmentNameTextBox->Location = System::Drawing::Point(13, 24);
			this->equipmentNameTextBox->Name = L"equipmentNameTextBox";
			this->equipmentNameTextBox->Size = System::Drawing::Size(312, 20);
			this->equipmentNameTextBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Equipment Name";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->updateEquipmentButton);
			this->tabPage2->Controls->Add(this->equipmentStockUpdate);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->equipmentDescriptionUpdate);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->equipmentNameUpdate);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(331, 260);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Update Equipment";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// updateEquipmentButton
			// 
			this->updateEquipmentButton->Location = System::Drawing::Point(131, 188);
			this->updateEquipmentButton->Name = L"updateEquipmentButton";
			this->updateEquipmentButton->Size = System::Drawing::Size(193, 65);
			this->updateEquipmentButton->TabIndex = 13;
			this->updateEquipmentButton->Text = L"UPDATE EQUIPMENT";
			this->updateEquipmentButton->UseVisualStyleBackColor = true;
			this->updateEquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPage::updateEquipmentButton_Click);
			// 
			// equipmentStockUpdate
			// 
			this->equipmentStockUpdate->Location = System::Drawing::Point(9, 188);
			this->equipmentStockUpdate->Name = L"equipmentStockUpdate";
			this->equipmentStockUpdate->Size = System::Drawing::Size(110, 20);
			this->equipmentStockUpdate->TabIndex = 12;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Equipment Stock";
			// 
			// equipmentDescriptionUpdate
			// 
			this->equipmentDescriptionUpdate->Location = System::Drawing::Point(12, 72);
			this->equipmentDescriptionUpdate->Multiline = true;
			this->equipmentDescriptionUpdate->Name = L"equipmentDescriptionUpdate";
			this->equipmentDescriptionUpdate->Size = System::Drawing::Size(312, 94);
			this->equipmentDescriptionUpdate->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 56);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Equipment Description";
			// 
			// equipmentNameUpdate
			// 
			this->equipmentNameUpdate->Location = System::Drawing::Point(12, 24);
			this->equipmentNameUpdate->Name = L"equipmentNameUpdate";
			this->equipmentNameUpdate->Size = System::Drawing::Size(312, 20);
			this->equipmentNameUpdate->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 8);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Equipment Name";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->deleteEquipmentButton);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(331, 260);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Delete Equipment";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// deleteEquipmentButton
			// 
			this->deleteEquipmentButton->Location = System::Drawing::Point(3, 144);
			this->deleteEquipmentButton->Name = L"deleteEquipmentButton";
			this->deleteEquipmentButton->Size = System::Drawing::Size(325, 96);
			this->deleteEquipmentButton->TabIndex = 14;
			this->deleteEquipmentButton->Text = L"DELETE EQUIPMENT";
			this->deleteEquipmentButton->UseVisualStyleBackColor = true;
			this->deleteEquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPage::deleteEquipmentButton_Click);
			// 
			// searchEquipmentTextBox
			// 
			this->searchEquipmentTextBox->Location = System::Drawing::Point(16, 85);
			this->searchEquipmentTextBox->Name = L"searchEquipmentTextBox";
			this->searchEquipmentTextBox->Size = System::Drawing::Size(331, 20);
			this->searchEquipmentTextBox->TabIndex = 8;
			this->searchEquipmentTextBox->TextChanged += gcnew System::EventHandler(this, &EquipmentPage::searchEquipmentTextBox_TextChanged);
			// 
			// searchEquipmentLabel
			// 
			this->searchEquipmentLabel->AutoSize = true;
			this->searchEquipmentLabel->Location = System::Drawing::Point(13, 69);
			this->searchEquipmentLabel->Name = L"searchEquipmentLabel";
			this->searchEquipmentLabel->Size = System::Drawing::Size(94, 13);
			this->searchEquipmentLabel->TabIndex = 7;
			this->searchEquipmentLabel->Text = L"Search Equipment";
			// 
			// equipmentHomeButton
			// 
			this->equipmentHomeButton->Location = System::Drawing::Point(16, 12);
			this->equipmentHomeButton->Name = L"equipmentHomeButton";
			this->equipmentHomeButton->Size = System::Drawing::Size(91, 44);
			this->equipmentHomeButton->TabIndex = 9;
			this->equipmentHomeButton->Text = L"HOME";
			this->equipmentHomeButton->UseVisualStyleBackColor = true;
			this->equipmentHomeButton->Click += gcnew System::EventHandler(this, &EquipmentPage::equipmentHomeButton_Click);
			// 
			// exportEquipmentButton
			// 
			this->exportEquipmentButton->Location = System::Drawing::Point(16, 415);
			this->exportEquipmentButton->Name = L"exportEquipmentButton";
			this->exportEquipmentButton->Size = System::Drawing::Size(99, 56);
			this->exportEquipmentButton->TabIndex = 10;
			this->exportEquipmentButton->Text = L"EXPORT PDF";
			this->exportEquipmentButton->UseVisualStyleBackColor = true;
			this->exportEquipmentButton->Click += gcnew System::EventHandler(this, &EquipmentPage::exportEquipmentButton_Click);
			// 
			// EquipmentPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(987, 588);
			this->Controls->Add(this->exportEquipmentButton);
			this->Controls->Add(this->equipmentHomeButton);
			this->Controls->Add(this->searchEquipmentTextBox);
			this->Controls->Add(this->searchEquipmentLabel);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->tblEquipment);
			this->Name = L"EquipmentPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EECE Inventory Tracker Equipment";
			this->Load += gcnew System::EventHandler(this, &EquipmentPage::EquipmentPage_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblEquipment))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->equipmentStockCount))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->equipmentStockUpdate))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Data::DataTable^ equipmentDataTable; //Needed to create dataTable object.
	public: Equipment^ equipment = nullptr; //Global variable which creates an object called equipment.

	private: System::Void EquipmentPage_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection sqlConn(connString);
		try {
			sqlConn.Open();
			SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM equipment", %sqlConn);
			SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);

			equipmentDataTable = gcnew DataTable();
			adapter->Fill(equipmentDataTable);
			tblEquipment->DataSource = equipmentDataTable;
			sqlConn.Close();
		}
		catch (SqlException^ ex) {
			MessageBox::Show("Failed to Read Data: " + ex->Message);
		}
	}
	private: System::Void addEquipmentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		equipment = gcnew Equipment;
		equipment->equipmentName = equipmentNameTextBox->Text;
		equipment->equipmentDesc = equipmentDescriptionTextBox->Text;
		equipment->equipmentStock = Convert::ToInt32(equipmentStockCount->Value);
		bool isValid = true;
		if (equipment->equipmentName->Trim()->Length <= 2) {
			MessageBox::Show("Enter A Valid Equipment Name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			isValid = false;
		}
		if (equipment->equipmentStock <= 0) {
			MessageBox::Show("Enter A Valid Equipment Stock Number.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			isValid = false;
		}

		if (isValid) {
			//INSERT DATA
			try {

				//Open the fckng connection
				String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
				SqlConnection^ sqlConn = gcnew SqlConnection(connString);
				sqlConn->Open();

				//Insert Query w/ Parameters
				String^ cmdString = "INSERT INTO equipment (name,stock,description) VALUES (@name, @stock, @desc)";
				String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
				
				SqlCommand^ cmd = gcnew SqlCommand(cmdString, sqlConn);
				SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, sqlConn);
				

				//Add Parameters to Command
				cmd->Parameters->AddWithValue("@name", equipment->equipmentName);
				cmd->Parameters->AddWithValue("@stock", equipment->equipmentStock);
				cmd->Parameters->AddWithValue("@desc", equipment->equipmentDesc);
				activityCMD->Parameters->AddWithValue("@act", "Add Equipment");
				activityCMD->Parameters->AddWithValue("@id", faculty->facultyNumber);
				activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));

				//JUST DO IT
				cmd->ExecuteNonQuery();
				activityCMD->ExecuteNonQuery();
				MessageBox::Show("Equipment added successfully.");
				sqlConn->Close();
				EquipmentPage_Load(sender, e); //Reloads the page.
				
				//REMOVES OLD DATA
				equipmentNameTextBox->Text = "";
				equipmentDescriptionTextBox->Text = "";
				equipmentStockCount->Value = 0;
			}

			catch(SqlException^ ex){
				MessageBox::Show("Failed to insert data: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
private: System::Void addImageButton_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void addEquipmentImageButton_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void tblEquipment_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

}
private: System::Void tblEquipment_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	
	equipmentNameUpdate->Text = "";
	equipmentDescriptionUpdate->Text = "";
	equipmentStockUpdate->Value = 0;

	//Checks if selected row isn't the header.
	if (e->RowIndex >= 0 && e->RowIndex < equipmentDataTable->Rows->Count) {
		// Retrieve data from the corresponding row in equipmentDataTable
		DataRow^ selectedRow = equipmentDataTable->Rows[e->RowIndex];

		// Assign values from the selected row to the respective controls
		equipmentNameUpdate->Text = selectedRow["name"]->ToString();
		equipmentDescriptionUpdate->Text = selectedRow["description"]->ToString();
		equipmentStockUpdate->Value = Convert::ToInt32(selectedRow["stock"]);
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {	
}
private: System::Void updateEquipmentButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ equipmentName = equipmentNameUpdate->Text;
	String^ equpmentDescription = equipmentDescriptionUpdate->Text;
	int equipmentStock = Convert::ToInt32(equipmentStockUpdate->Value);

	String^ currEquipmentID = tblEquipment->Rows[tblEquipment->CurrentCell->RowIndex]->Cells[0]->Value->ToString(); //Gets current row selected
	try {

		//Open the fckng connection
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();

		//Update Query w/ Parameters
		String^ cmdString = "UPDATE equipment SET name=@equipmentName,description=@equipmentDescription,stock=@equipmentStock WHERE equipmentID= " + currEquipmentID;
		String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";

		SqlCommand^ cmd = gcnew SqlCommand(cmdString, sqlConn);
		SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, sqlConn);


		//Add Parameters to Command
		cmd->Parameters->AddWithValue("@equipmentName", equipmentName);
		cmd->Parameters->AddWithValue("@equipmentDescription", equpmentDescription);
		cmd->Parameters->AddWithValue("@equipmentStock", equipmentStock);
		activityCMD->Parameters->AddWithValue("@act", "Update Equipment");
		activityCMD->Parameters->AddWithValue("@id", faculty->facultyNumber);
		activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));

		//JUST DO IT
		cmd->ExecuteNonQuery();
		activityCMD->ExecuteNonQuery();
		MessageBox::Show("Equipment updated successfully.");
		sqlConn->Close();
		EquipmentPage_Load(sender, e); //Reloads the page.

		//REMOVES OLD DATA
		equipmentNameTextBox->Text = "";
		equipmentDescriptionTextBox->Text = "";
		equipmentStockCount->Value = 0;
	}

	catch (SqlException^ ex) {
		MessageBox::Show("Failed to update data: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void deleteEquipmentButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ currEquipmentID = tblEquipment->Rows[tblEquipment->CurrentCell->RowIndex]->Cells[0]->Value->ToString(); //Gets current row selected

	try {

		//Open the fckng connection
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();

		//Update Query w/ Parameters
		String^ cmdString = "DELETE FROM equipment WHERE equipmentID= " + currEquipmentID;
		String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
		SqlCommand^ cmd = gcnew SqlCommand(cmdString, sqlConn);
		SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, sqlConn);
		activityCMD->Parameters->AddWithValue("@act", "Delete Equipment");
		activityCMD->Parameters->AddWithValue("@id", faculty->facultyNumber);
		activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));

		//JUST DO IT
		cmd->ExecuteNonQuery();
		activityCMD->ExecuteNonQuery();
		MessageBox::Show("Equipment deleted successfully.");
		sqlConn->Close();
		EquipmentPage_Load(sender, e); //Reloads the page.

		//REMOVES OLD DATA
		equipmentNameTextBox->Text = "";
		equipmentDescriptionTextBox->Text = "";
		equipmentStockCount->Value = 0;
	}

	catch (SqlException^ ex) {
		MessageBox::Show("Failed to delete data: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}
private: System::Void searchEquipmentTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ searchKeyword = searchEquipmentTextBox->Text;

	try {

		//Open the fckng connection
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();

		//Update Query w/ Parameters
		String^ cmdString = "SELECT * FROM equipment WHERE name LIKE @searchKeyword";
		SqlCommand^ cmd = gcnew SqlCommand(cmdString, sqlConn);
		cmd->Parameters->AddWithValue("@searchKeyword", searchKeyword + "%");

		// Use SqlDataAdapter to fetch results
		SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
		equipmentDataTable->Clear();
		adapter->Fill(equipmentDataTable);

		//JUST DO IT
		tblEquipment->DataSource = equipmentDataTable;
		sqlConn->Close();
	}

	catch (SqlException^ ex) {
		MessageBox::Show("Failed to search equipment: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void equipmentHomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	///Code for Transitioning Back to Home Page///
	this->Hide();
	mainPage->Show();
	//////////////////////////////////////////////
}
void ExportDataGridViewToPdf(System::Windows::Forms::DataGridView^ dgv, String^ filePath)
{
	// Create a new document (A4 size, landscape)
	Document^ document = gcnew Document(PageSize::A4->Rotate()); // No need to use Rotate() separately
	PdfWriter::GetInstance(document, gcnew FileStream(filePath, FileMode::Create));
	document->Open();

	// Create a PdfPTable with the same number of columns as the DataGridView
	PdfPTable^ pdfTable = gcnew PdfPTable(dgv->ColumnCount);
	pdfTable->WidthPercentage = 100; // Set table to take full width of the page
	pdfTable->SpacingBefore = 10;
	pdfTable->SpacingAfter = 10;

	// Set header font and row font (iTextSharp font)
	iTextSharp::text::Font^ headerFont = gcnew iTextSharp::text::Font(iTextSharp::text::Font::FontFamily::HELVETICA, 12, iTextSharp::text::Font::BOLD, BaseColor::WHITE);
	iTextSharp::text::Font^ rowFont = gcnew iTextSharp::text::Font(iTextSharp::text::Font::FontFamily::HELVETICA, 10, iTextSharp::text::Font::NORMAL, BaseColor::BLACK);

	// Set alternating row colors
	BaseColor^ alternateRowColor = BaseColor::LIGHT_GRAY;
	BaseColor^ whiteColor = BaseColor::WHITE;

	// Add headers to the PDF table
	for (int j = 0; j < dgv->ColumnCount; j++)
	{
		PdfPCell^ headerCell = gcnew PdfPCell(gcnew Phrase(dgv->Columns[j]->HeaderText, headerFont));
		headerCell->HorizontalAlignment = Element::ALIGN_CENTER;
		headerCell->BackgroundColor = BaseColor::DARK_GRAY;
		headerCell->Padding = 5;
		pdfTable->AddCell(headerCell);
	}

	// Add the rows from the DataGridView to the PDF table
	for (int i = 0; i < dgv->Rows->Count; i++)
	{
		for (int j = 0; j < dgv->ColumnCount; j++)
		{
			String^ cellValue = dgv->Rows[i]->Cells[j]->Value == nullptr ? "" : dgv->Rows[i]->Cells[j]->Value->ToString();
			PdfPCell^ cell = gcnew PdfPCell(gcnew Phrase(cellValue, rowFont));

			// Set alternating row colors
			if (i % 2 == 0)
			{
				cell->BackgroundColor = alternateRowColor;
			}
			else
			{
				cell->BackgroundColor = whiteColor;
			}

			// Add padding and alignment to the cell
			cell->Padding = 5;
			cell->HorizontalAlignment = Element::ALIGN_LEFT;
			pdfTable->AddCell(cell);
		}
	}

	// Add the PDF table to the document
	document->Add(pdfTable);
	document->Close();
}

String^ getFilePath() {
	FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();

	// Set description (optional)
	fbd->Description = "Select a folder to save your file";

	// Show the FolderBrowserDialog and check if the user selected a folder
	if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Get the selected folder path
		String^ folderPath = fbd->SelectedPath;

		// Append a file name to the selected folder
		String^ fileName = "Equipment.pdf"; // Change this to whatever file name you want
		return folderPath + "\\" + fileName;
	}

	// If no folder was selected, return nullptr
	return nullptr;
}

private: System::Void exportEquipmentButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ filePath = getFilePath();

	// Check if a valid file path was selected
	if (filePath != nullptr) {
		ExportDataGridViewToPdf(tblEquipment, filePath);
		MessageBox::Show("File saved at: " + filePath);

		//Log Export PDF Activity
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();
		String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
		SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, sqlConn);
		activityCMD->Parameters->AddWithValue("@act", "Export Equipment PDF");
		activityCMD->Parameters->AddWithValue("@id", faculty->facultyNumber);
		activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));
		activityCMD->ExecuteNonQuery();
		sqlConn->Close();
	}
	else {
		MessageBox::Show("No folder selected.");
	}

}
};
}
