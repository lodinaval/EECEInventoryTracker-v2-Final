#pragma once
#include "Equipment.h"
#include "Student.h"
#include "Faculty.h"
#include "ExperimentPage.h"

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
	/// Summary for BorrowPage
	/// </summary>
	public ref class BorrowPage : public System::Windows::Forms::Form
	{
	private: System::Data::DataTable^ equipmentDataTable; //Needed to create dataTable object.
	public: System::Data::DataTable^ cartDataTable; //Needed to create cart table object.
	public: Equipment^ equipment = nullptr; //Global variable which creates an object called equipment.
	public: System::Windows::Forms::DataGridView^ tblBorrow;
	public:

	public:
	public:
		Form^ MainPage;
		Student^ student;
		Faculty^ faculty;
	private: System::Windows::Forms::Label^ studentNumberInfo;
	private: System::Windows::Forms::Button^ browseExperimentButton;
	private: System::Windows::Forms::Panel^ experimentPanel;
	private: System::Windows::Forms::Button^ experimentAddToCartButton;
	private: System::Windows::Forms::Button^ experimentReturnButton;
	private: System::Windows::Forms::ComboBox^ experimentComboBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ tblExperiment;


	private: System::Windows::Forms::Label^ studentNameInfo;
	public:
		BorrowPage(Student^ studentL, Faculty^ facultyL, Form^ mainPage)
		{
			InitializeComponent();
			MainPage = mainPage;
			student = studentL;
			faculty = facultyL;
			if (student == nullptr) {
				studentNameInfo->Text = faculty->name;
				studentNumberInfo->Text = Convert::ToString(faculty->facultyNumber);
			}
			if (faculty == nullptr) {
				studentNameInfo->Text = student->name;
				studentNumberInfo->Text = Convert::ToString(student->studentNumber);
			}
			cartDataTable = gcnew System::Data::DataTable();
			cartDataTable->Columns->Add("ID", int::typeid);
			cartDataTable->Columns->Add("Name", String::typeid);
			cartDataTable->Columns->Add("Description", String::typeid);
			cartDataTable->Columns->Add("Stock", int::typeid);

			// Set cartDataTable as the DataSource for tblBorrow
			tblBorrow->DataSource = cartDataTable;
			tblBorrow->Columns["ID"]->ReadOnly = true;
			tblBorrow->Columns["Name"]->ReadOnly = true;
			tblBorrow->Columns["Description"]->ReadOnly = true;
			tblBorrow->Columns["Stock"]->ReadOnly = false;

			//Makes sure that the borrowFrom date picker minimum date is today.
			borrowFrom->MinDate = DateTime::Today;
			borrowTo->MinDate = DateTime::Today;
			//
			//TODO: Add the constructor code here
			//
		}
		
		BorrowPage(void)
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
		~BorrowPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ tblEquipment;

	private: System::Windows::Forms::Button^ addToCartButton;
	private: System::Windows::Forms::DateTimePicker^ borrowFrom;
	private: System::Windows::Forms::DateTimePicker^ borrowTo;
	protected:




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ deleteButton;

	private: System::Windows::Forms::TextBox^ searchEquipmentTextBox;
	private: System::Windows::Forms::Label^ searchEquipmentLabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ checkoutButton;

	private: System::Windows::Forms::Button^ equipmentHomeButton;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BorrowPage::typeid));
			this->tblEquipment = (gcnew System::Windows::Forms::DataGridView());
			this->addToCartButton = (gcnew System::Windows::Forms::Button());
			this->borrowFrom = (gcnew System::Windows::Forms::DateTimePicker());
			this->borrowTo = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->searchEquipmentTextBox = (gcnew System::Windows::Forms::TextBox());
			this->searchEquipmentLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkoutButton = (gcnew System::Windows::Forms::Button());
			this->equipmentHomeButton = (gcnew System::Windows::Forms::Button());
			this->tblBorrow = (gcnew System::Windows::Forms::DataGridView());
			this->studentNumberInfo = (gcnew System::Windows::Forms::Label());
			this->studentNameInfo = (gcnew System::Windows::Forms::Label());
			this->browseExperimentButton = (gcnew System::Windows::Forms::Button());
			this->experimentPanel = (gcnew System::Windows::Forms::Panel());
			this->experimentAddToCartButton = (gcnew System::Windows::Forms::Button());
			this->experimentReturnButton = (gcnew System::Windows::Forms::Button());
			this->experimentComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tblExperiment = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblEquipment))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblBorrow))->BeginInit();
			this->experimentPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblExperiment))->BeginInit();
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
			resources->ApplyResources(this->tblEquipment, L"tblEquipment");
			this->tblEquipment->Name = L"tblEquipment";
			this->tblEquipment->ReadOnly = true;
			this->tblEquipment->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->tblEquipment->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &BorrowPage::tblEquipment_CellClick);
			this->tblEquipment->Click += gcnew System::EventHandler(this, &BorrowPage::tblEquipment_Click);
			// 
			// addToCartButton
			// 
			resources->ApplyResources(this->addToCartButton, L"addToCartButton");
			this->addToCartButton->Name = L"addToCartButton";
			this->addToCartButton->UseVisualStyleBackColor = true;
			this->addToCartButton->Click += gcnew System::EventHandler(this, &BorrowPage::button1_Click);
			// 
			// borrowFrom
			// 
			resources->ApplyResources(this->borrowFrom, L"borrowFrom");
			this->borrowFrom->MinDate = System::DateTime(2024, 11, 2, 11, 7, 56, 0);
			this->borrowFrom->Name = L"borrowFrom";
			this->borrowFrom->Value = System::DateTime(2024, 11, 2, 11, 7, 56, 0);
			this->borrowFrom->ValueChanged += gcnew System::EventHandler(this, &BorrowPage::borrowFrom_ValueChanged);
			// 
			// borrowTo
			// 
			resources->ApplyResources(this->borrowTo, L"borrowTo");
			this->borrowTo->Name = L"borrowTo";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// deleteButton
			// 
			resources->ApplyResources(this->deleteButton, L"deleteButton");
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &BorrowPage::button2_Click);
			// 
			// searchEquipmentTextBox
			// 
			resources->ApplyResources(this->searchEquipmentTextBox, L"searchEquipmentTextBox");
			this->searchEquipmentTextBox->Name = L"searchEquipmentTextBox";
			this->searchEquipmentTextBox->TextChanged += gcnew System::EventHandler(this, &BorrowPage::searchEquipmentTextBox_TextChanged);
			// 
			// searchEquipmentLabel
			// 
			resources->ApplyResources(this->searchEquipmentLabel, L"searchEquipmentLabel");
			this->searchEquipmentLabel->Name = L"searchEquipmentLabel";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// checkoutButton
			// 
			resources->ApplyResources(this->checkoutButton, L"checkoutButton");
			this->checkoutButton->Name = L"checkoutButton";
			this->checkoutButton->UseVisualStyleBackColor = true;
			this->checkoutButton->Click += gcnew System::EventHandler(this, &BorrowPage::button3_Click);
			// 
			// equipmentHomeButton
			// 
			resources->ApplyResources(this->equipmentHomeButton, L"equipmentHomeButton");
			this->equipmentHomeButton->Name = L"equipmentHomeButton";
			this->equipmentHomeButton->UseVisualStyleBackColor = true;
			this->equipmentHomeButton->Click += gcnew System::EventHandler(this, &BorrowPage::equipmentHomeButton_Click);
			// 
			// tblBorrow
			// 
			this->tblBorrow->AllowUserToAddRows = false;
			this->tblBorrow->AllowUserToDeleteRows = false;
			this->tblBorrow->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tblBorrow->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->tblBorrow->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			resources->ApplyResources(this->tblBorrow, L"tblBorrow");
			this->tblBorrow->Name = L"tblBorrow";
			this->tblBorrow->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			// 
			// studentNumberInfo
			// 
			resources->ApplyResources(this->studentNumberInfo, L"studentNumberInfo");
			this->studentNumberInfo->BackColor = System::Drawing::Color::Transparent;
			this->studentNumberInfo->Name = L"studentNumberInfo";
			// 
			// studentNameInfo
			// 
			resources->ApplyResources(this->studentNameInfo, L"studentNameInfo");
			this->studentNameInfo->BackColor = System::Drawing::Color::Transparent;
			this->studentNameInfo->Name = L"studentNameInfo";
			// 
			// browseExperimentButton
			// 
			resources->ApplyResources(this->browseExperimentButton, L"browseExperimentButton");
			this->browseExperimentButton->Name = L"browseExperimentButton";
			this->browseExperimentButton->UseVisualStyleBackColor = true;
			this->browseExperimentButton->Click += gcnew System::EventHandler(this, &BorrowPage::browseExperimentButton_Click);
			// 
			// experimentPanel
			// 
			this->experimentPanel->Controls->Add(this->experimentAddToCartButton);
			this->experimentPanel->Controls->Add(this->experimentReturnButton);
			this->experimentPanel->Controls->Add(this->experimentComboBox);
			this->experimentPanel->Controls->Add(this->label4);
			this->experimentPanel->Controls->Add(this->tblExperiment);
			resources->ApplyResources(this->experimentPanel, L"experimentPanel");
			this->experimentPanel->Name = L"experimentPanel";
			// 
			// experimentAddToCartButton
			// 
			resources->ApplyResources(this->experimentAddToCartButton, L"experimentAddToCartButton");
			this->experimentAddToCartButton->Name = L"experimentAddToCartButton";
			this->experimentAddToCartButton->UseVisualStyleBackColor = true;
			this->experimentAddToCartButton->Click += gcnew System::EventHandler(this, &BorrowPage::experimentAddToCartButton_Click);
			// 
			// experimentReturnButton
			// 
			resources->ApplyResources(this->experimentReturnButton, L"experimentReturnButton");
			this->experimentReturnButton->Name = L"experimentReturnButton";
			this->experimentReturnButton->UseVisualStyleBackColor = true;
			this->experimentReturnButton->Click += gcnew System::EventHandler(this, &BorrowPage::experimentReturnButton_Click);
			// 
			// experimentComboBox
			// 
			this->experimentComboBox->DropDownHeight = 300;
			this->experimentComboBox->DropDownWidth = 250;
			this->experimentComboBox->FormattingEnabled = true;
			resources->ApplyResources(this->experimentComboBox, L"experimentComboBox");
			this->experimentComboBox->Name = L"experimentComboBox";
			this->experimentComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &BorrowPage::experimentComboBox_SelectedIndexChanged);
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// tblExperiment
			// 
			this->tblExperiment->AllowUserToAddRows = false;
			this->tblExperiment->AllowUserToDeleteRows = false;
			this->tblExperiment->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tblExperiment->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->tblExperiment->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			resources->ApplyResources(this->tblExperiment, L"tblExperiment");
			this->tblExperiment->Name = L"tblExperiment";
			this->tblExperiment->ReadOnly = true;
			// 
			// BorrowPage
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->experimentPanel);
			this->Controls->Add(this->browseExperimentButton);
			this->Controls->Add(this->studentNumberInfo);
			this->Controls->Add(this->studentNameInfo);
			this->Controls->Add(this->tblBorrow);
			this->Controls->Add(this->equipmentHomeButton);
			this->Controls->Add(this->checkoutButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->searchEquipmentTextBox);
			this->Controls->Add(this->searchEquipmentLabel);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->borrowTo);
			this->Controls->Add(this->borrowFrom);
			this->Controls->Add(this->addToCartButton);
			this->Controls->Add(this->tblEquipment);
			this->Name = L"BorrowPage";
			this->Load += gcnew System::EventHandler(this, &BorrowPage::BorrowPage_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblEquipment))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblBorrow))->EndInit();
			this->experimentPanel->ResumeLayout(false);
			this->experimentPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblExperiment))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void equipmentHomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MainPage->Show();
	}
private: System::Void BorrowPage_Load(System::Object^ sender, System::EventArgs^ e) {
	experimentPanel->Hide();
	//Initialize Equipment:
	equipment = gcnew Equipment;
	tblEquipment->ClearSelection();
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);
	try {
		//Load Equipment
		sqlConn.Open();
		SqlCommand^ cmdEquipment = gcnew SqlCommand("SELECT * from equipment WHERE stock != 0", % sqlConn);
		SqlDataAdapter^ equipmentAdapter = gcnew SqlDataAdapter(cmdEquipment);

		equipmentDataTable = gcnew DataTable();
		equipmentAdapter->Fill(equipmentDataTable);
		tblEquipment->DataSource = equipmentDataTable;

		sqlConn.Close();
	}
	catch (SqlException^ ex) {
		MessageBox::Show("Failed to Read Data: " + ex->Message);
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
private: System::Void tblEquipment_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tblEquipment_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	//Checks if selected row isn't the header.
	if (e->RowIndex >= 0 && e->RowIndex < equipmentDataTable->Rows->Count) {
		// Retrieve data from the corresponding row in equipmentDataTable
		DataRow^ selectedRow = equipmentDataTable->Rows[e->RowIndex];

		// Assign values from the selected row to the respective controls
		equipment->equipmentName = selectedRow["name"]->ToString();
		equipment->equipmentID = Convert::ToInt32(selectedRow["equipmentID"]);
		equipment->equipmentDesc = selectedRow["description"]->ToString();
		equipment->equipmentStock = Convert::ToInt32(selectedRow["stock"]);
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	//Checks if may laman sinelect.
	if (String::IsNullOrEmpty(equipment->equipmentName) || String::IsNullOrEmpty(equipment->equipmentDesc)) {
		MessageBox::Show("Please select an item from the Equipment table first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	bool itemExists = false;
	for each (DataRow ^ row in cartDataTable->Rows) {
		if (row["Name"]->ToString() == equipment->equipmentName && row["Description"]->ToString() == equipment->equipmentDesc) {  // Check by name or unique ID
			itemExists = true;
			break;
		}
	}

	if (!itemExists) {
		DataRow^ cartRow = cartDataTable->NewRow();
		cartRow["ID"] = equipment->equipmentID;
		cartRow["Name"] = equipment->equipmentName;
		cartRow["Description"] = equipment->equipmentDesc;
		cartRow["Stock"] = equipment->equipmentStock;
		cartDataTable->Rows->Add(cartRow);
	}
	else {
		MessageBox::Show("Error: Item is already in the cart.");
	}

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if there is a selected row
	if (tblBorrow->SelectedRows->Count > 0) {
		// Get the index of the selected row
		int rowIndex = tblBorrow->SelectedRows[0]->Index;

		// Remove the row from the DataTable
		cartDataTable->Rows->RemoveAt(rowIndex);
	}
	else {
		MessageBox::Show("Please select a row to delete.", "Delete Row", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	if (tblBorrow == nullptr || tblBorrow->Rows->Count == 0) {
		MessageBox::Show("No items in the cart to checkout.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	bool stockIsSufficient = true;  // Track if stock is enough for all items
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);

	// Step 1: Check stock availability
	for (int i = 0; i < tblBorrow->Rows->Count; i++) {
		String^ equipmentName = tblBorrow->Rows[i]->Cells["Name"]->Value->ToString();
		int requestedQuantity = Convert::ToInt32(tblBorrow->Rows[i]->Cells["Stock"]->Value);

		sqlConn.Open();
		String^ query = "SELECT stock FROM equipment WHERE name = @equipmentName";
		SqlCommand^ cmd = gcnew SqlCommand(query, % sqlConn);
		cmd->Parameters->AddWithValue("@equipmentName", equipmentName);
		SqlDataReader^ reader = cmd->ExecuteReader();

		if (reader->Read()) {
			int availableStock = reader->GetInt32(0);
			if (requestedQuantity < 0) {
				MessageBox::Show("Invalid stock number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (requestedQuantity > availableStock) {
				MessageBox::Show("Insufficient stock for " + equipmentName, "Stock Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				stockIsSufficient = false;
			}
		}
		else {
			MessageBox::Show("Item " + equipmentName + " not found in inventory.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			stockIsSufficient = false;
		}

		reader->Close();
		sqlConn.Close();

		if (!stockIsSufficient) {
			break;
		}
	}

	// Step 2: If stock is sufficient, proceed with the checkout
	if (stockIsSufficient) {
		sqlConn.Open();

		// Retrieve and increment the transaction ID
		SqlCommand^ getMaxTransactionID = gcnew SqlCommand("SELECT ISNULL(MAX(transactionID), 0) + 1 FROM borrowedEquipment", % sqlConn);
		int transactionID = (int)getMaxTransactionID->ExecuteScalar();

		sqlConn.Close();

		// Insert each borrowed item with the same transaction ID
		for (int i = 0; i < tblBorrow->Rows->Count; i++) {
			int equipmentID = Convert::ToInt32(tblBorrow->Rows[i]->Cells["ID"]->Value);
			String^ equipmentName = tblBorrow->Rows[i]->Cells["Name"]->Value->ToString();
			String^ equipmentDescription = tblBorrow->Rows[i]->Cells["Description"]->Value->ToString();
			int requestedQuantity = Convert::ToInt32(tblBorrow->Rows[i]->Cells["Stock"]->Value);
			String^ equipmentBorrowFrom = borrowFrom->Value.ToString("MM-dd-yyyy");
			String^ equipmentBorrowTo = borrowTo->Value.ToString("MM-dd-yyyy");
			String^ transactionDate = DateTime::Today.ToString("MM-dd-yyyy");
			sqlConn.Open();
			String^ query = "INSERT INTO borrowedEquipment (transactionID, equipmentID, equipmentName, equipmentDescription, equipmentStock, equipmentBorrowFrom, equipmentBorrowTo, studentID, status, transactionDate) VALUES (@tid, @eid, @name, @desc, @stock, @borrowfrom, @borrowto, @sid, @stat, @transDate)";
			SqlCommand^ cmd = gcnew SqlCommand(query, % sqlConn);
			cmd->Parameters->AddWithValue("@tid", transactionID);
			cmd->Parameters->AddWithValue("@eid", equipmentID);
			cmd->Parameters->AddWithValue("@name", equipmentName);
			cmd->Parameters->AddWithValue("@desc", equipmentDescription);
			cmd->Parameters->AddWithValue("@stock", requestedQuantity);
			cmd->Parameters->AddWithValue("@borrowfrom", equipmentBorrowFrom);
			cmd->Parameters->AddWithValue("@borrowto", equipmentBorrowTo);
			if (student != nullptr) {
				cmd->Parameters->AddWithValue("@sid", student->studentNumber);
			}
			else if (faculty != nullptr) {
				cmd->Parameters->AddWithValue("@sid", faculty->facultyNumber);
			}
			else {
				MessageBox::Show("Error: No valid user identified.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			cmd->Parameters->AddWithValue("@stat", "Pending");
			cmd->Parameters->AddWithValue("@transDate", transactionDate);

			cmd->ExecuteNonQuery();
			sqlConn.Close();
		}

		MessageBox::Show("Checkout successful! Please wait for approval from the faculty members", "Borrow Request", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Hide();
		MainPage->Show();
	}

	//Last Step: Add to Activity Log:
	sqlConn.Open();
	String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
	SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, % sqlConn);
	activityCMD->Parameters->AddWithValue("@act", "Borrow Equipment");
	activityCMD->Parameters->AddWithValue("@id", faculty->facultyNumber);
	activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));

	activityCMD->ExecuteNonQuery();
}
private: System::Void browseExperimentButton_Click(System::Object^ sender, System::EventArgs^ e) {
	//this->Hide();
	//ExperimentPage^ experimentPage = gcnew ExperimentPage(this);
	//experimentPage->Show();

	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);

	try {
		sqlConn.Open();

		SqlCommand^ cmd = gcnew SqlCommand("SELECT DISTINCT [Experiment Number], [Experiment Name] FROM experiments", % sqlConn);
		SqlDataReader^ reader = cmd->ExecuteReader();

		experimentComboBox->Items->Clear();

		// Check for the existence of data before adding to ComboBox
		if (reader->HasRows) {
			while (reader->Read()) {
				int experimentNumber = reader->GetInt32(0);  // Assuming it's the first column
				String^ experimentName = reader->GetString(1);  // Assuming it's the second column
				String^ formattedText = "Experiment " + experimentNumber + ": " + experimentName;
				experimentComboBox->Items->Add(formattedText);
			}
		}
		else {
			experimentComboBox->Items->Add("No experiments available");
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ ex) {
		MessageBox::Show("Failed to load experiments: " + ex->Message);
	}
	experimentPanel->Show();
}
private: System::Void experimentReturnButton_Click(System::Object^ sender, System::EventArgs^ e) {
	experimentPanel->Hide();
}
private: System::Void experimentAddToCartButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);
	sqlConn.Open();
	//TRUNCATE experimentToEquipment
	SqlCommand^ cmdDelete = gcnew SqlCommand("DELETE FROM experimentToEquipment", % sqlConn);
	cmdDelete->ExecuteNonQuery();
	sqlConn.Close();

	for (int i = 0; i < tblExperiment->Rows->Count; i++) {
		int equipmentID = Convert::ToInt32(tblExperiment->Rows[i]->Cells["Equipment ID"]->Value);
		String^ equipmentName = tblExperiment->Rows[i]->Cells["Equipment"]->Value->ToString();
		String^ equipmentDesc = tblExperiment->Rows[i]->Cells["Equipment Description"]->Value->ToString();
		int equipmentStock = Convert::ToInt32(tblExperiment->Rows[i]->Cells["Equipment Stock"]->Value);

		try {
			sqlConn.Open();
			// INSERT syntax
			SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO experimentToEquipment (equipmentID, equipmentName, equipmentDescription, equipmentStock) VALUES (@id, @ename, @edesc, @estock)", % sqlConn);

			// Adding parameters
			cmd->Parameters->AddWithValue("@id", equipmentID);
			cmd->Parameters->AddWithValue("@ename", equipmentName);
			cmd->Parameters->AddWithValue("@edesc", equipmentDesc);
			cmd->Parameters->AddWithValue("@estock", equipmentStock);

			cmd->ExecuteNonQuery();
		}
		catch (SqlException^ ex) {
			MessageBox::Show("Error inserting data: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlConn.Close(); // Ensure connection is closed
		}
	}
	try {
		sqlConn.Open();
		SqlCommand^ cmd = gcnew SqlCommand("SELECT equipmentID, equipmentName, equipmentDescription, equipmentStock FROM experimentToEquipment", % sqlConn);
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read()) {
			DataRow^ cartRow = cartDataTable->NewRow();
			cartRow["ID"] = Convert::ToInt32(reader["equipmentID"]);
			cartRow["Name"] = reader["equipmentName"]->ToString();
			cartRow["Description"] = reader["equipmentDescription"]->ToString();
			cartRow["Stock"] = Convert::ToInt32(reader["equipmentStock"]);

			cartDataTable->Rows->Add(cartRow);  // Add row to cartDataTable
		}
		reader->Close();
	}
	catch (SqlException^ ex) {
		MessageBox::Show("Failed to load data from experimentToEquipment: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		sqlConn.Close();  // Ensure the connection is closed
	}
	MessageBox::Show("Experiment equipment added to cart successfully");
	experimentPanel->Hide();
}
private: System::Void experimentComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (experimentComboBox->SelectedItem == nullptr) {
		return; // Prevents accessing a null item
	}

	String^ selectedText = experimentComboBox->SelectedItem->ToString();
	int experimentNumber = Convert::ToInt32(selectedText->Substring(11, 1)); // Adjust the substring if needed

	DataTable^ experimentDataTable = gcnew DataTable();
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);

	try {
		sqlConn.Open();
		String^ query = "SELECT [Equipment ID], [Equipment], [Equipment Description], [Equipment Stock] FROM experiments WHERE [Experiment Number] = @experimentNum";
		SqlCommand^ cmd = gcnew SqlCommand(query, % sqlConn);
		cmd->Parameters->AddWithValue("@experimentNum", experimentNumber);

		SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
		adapter->Fill(experimentDataTable);
		tblExperiment->DataSource = experimentDataTable;
	}
	catch (SqlException^ ex) {
		MessageBox::Show("Failed to load experiments: " + ex->Message);
	}
	finally {
		sqlConn.Close(); // Ensures connection closes in case of an exception
	}
}
private: System::Void borrowFrom_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	borrowTo->MinDate = borrowFrom->Value;
}
};
}
