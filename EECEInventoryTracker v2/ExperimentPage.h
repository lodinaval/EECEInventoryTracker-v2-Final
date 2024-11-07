#pragma once

namespace EECEInventoryTrackerv2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data::SqlClient;
	using namespace System::IO;

	/// <summary>
	/// Summary for ExperimentPage
	/// </summary>
	public ref class ExperimentPage : public System::Windows::Forms::Form
	{
	public:
		Form^ mainPage;
		ExperimentPage(Form^ MainPage)
		{
			InitializeComponent();
			mainPage = MainPage;
			//
			//TODO: Add the constructor code here
			//
		}
		ExperimentPage(void)
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
		~ExperimentPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ tblExperiment;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ experimentComboBox;
	private: System::Windows::Forms::Button^ experimentReturnButton;
	private: System::Windows::Forms::Button^ experimentAddToCartButton;
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
			this->tblExperiment = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->experimentComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->experimentReturnButton = (gcnew System::Windows::Forms::Button());
			this->experimentAddToCartButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblExperiment))->BeginInit();
			this->SuspendLayout();
			// 
			// tblExperiment
			// 
			this->tblExperiment->AllowUserToAddRows = false;
			this->tblExperiment->AllowUserToDeleteRows = false;
			this->tblExperiment->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tblExperiment->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->tblExperiment->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tblExperiment->Location = System::Drawing::Point(25, 58);
			this->tblExperiment->Name = L"tblExperiment";
			this->tblExperiment->ReadOnly = true;
			this->tblExperiment->Size = System::Drawing::Size(682, 456);
			this->tblExperiment->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(160, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(226, 16);
			this->label1->TabIndex = 16;
			this->label1->Text = L"LOGIC CIRCUIT EXPERIMENTS";
			// 
			// experimentComboBox
			// 
			this->experimentComboBox->DropDownHeight = 300;
			this->experimentComboBox->DropDownWidth = 250;
			this->experimentComboBox->FormattingEnabled = true;
			this->experimentComboBox->IntegralHeight = false;
			this->experimentComboBox->Location = System::Drawing::Point(139, 31);
			this->experimentComboBox->Name = L"experimentComboBox";
			this->experimentComboBox->Size = System::Drawing::Size(270, 21);
			this->experimentComboBox->TabIndex = 17;
			this->experimentComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ExperimentPage::experimentComboBox_SelectedIndexChanged);
			// 
			// experimentReturnButton
			// 
			this->experimentReturnButton->Location = System::Drawing::Point(25, 13);
			this->experimentReturnButton->Name = L"experimentReturnButton";
			this->experimentReturnButton->Size = System::Drawing::Size(98, 39);
			this->experimentReturnButton->TabIndex = 18;
			this->experimentReturnButton->Text = L"RETURN";
			this->experimentReturnButton->UseVisualStyleBackColor = true;
			this->experimentReturnButton->Click += gcnew System::EventHandler(this, &ExperimentPage::experimentReturnButton_Click);
			// 
			// experimentAddToCartButton
			// 
			this->experimentAddToCartButton->Location = System::Drawing::Point(415, 12);
			this->experimentAddToCartButton->Name = L"experimentAddToCartButton";
			this->experimentAddToCartButton->Size = System::Drawing::Size(139, 39);
			this->experimentAddToCartButton->TabIndex = 19;
			this->experimentAddToCartButton->Text = L"ADD TO CART";
			this->experimentAddToCartButton->UseVisualStyleBackColor = true;
			this->experimentAddToCartButton->Click += gcnew System::EventHandler(this, &ExperimentPage::experimentAddToCartButton_Click);
			// 
			// ExperimentPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 538);
			this->Controls->Add(this->experimentAddToCartButton);
			this->Controls->Add(this->experimentReturnButton);
			this->Controls->Add(this->experimentComboBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tblExperiment);
			this->Name = L"ExperimentPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EECE Inventory Tracker";
			this->Load += gcnew System::EventHandler(this, &ExperimentPage::ExperimentPage_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblExperiment))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void experimentReturnButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		mainPage->Show();
	}
private: System::Void ExperimentPage_Load(System::Object^ sender, System::EventArgs^ e) {
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
		String^ query = "SELECT [Equipment], [Equipment Description], [Equipment Stock] FROM experiments WHERE [Experiment Number] = @experimentNum";
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
private: System::Void experimentAddToCartButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);
	sqlConn.Open();
	//TRUNCATE experimentToEquipment
	SqlCommand^ cmdDelete = gcnew SqlCommand("DELETE FROM experimentToEquipment", % sqlConn);
	cmdDelete->ExecuteNonQuery();
	sqlConn.Close();

	for (int i = 0; i < tblExperiment->Rows->Count; i++) {
		String^ equipmentName = tblExperiment->Rows[i]->Cells["Equipment"]->Value->ToString();
		String^ equipmentDesc = tblExperiment->Rows[i]->Cells["Equipment Description"]->Value->ToString();
		int equipmentStock = Convert::ToInt32(tblExperiment->Rows[i]->Cells["Equipment Stock"]->Value);

		try {
			sqlConn.Open();
			// INSERT syntax
			SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO experimentToEquipment (equipmentName, equipmentDescription, equipmentStock) VALUES (@ename, @edesc, @estock)", % sqlConn);

			// Adding parameters
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
	this->Hide();
	MessageBox::Show("Experiment equipment added to cart successfully");
	mainPage->Show();
}
};
}
