#pragma once
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
	/// Summary for TransactionsPage
	/// </summary>
	public ref class TransactionsPage : public System::Windows::Forms::Form
	{
	public:
		Form^ mainPage;
		Faculty^ faculty;
		TransactionsPage(Faculty^ facultyL, Form^ mainPageL)
		{
			InitializeComponent();
			mainPage = mainPageL;
			faculty = facultyL;
			//
			//TODO: Add the constructor code here
			//
		}

		TransactionsPage(void)
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
		~TransactionsPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ transactionsHomeButton;
	private: System::Windows::Forms::DataGridView^ tblTransactions;


	private: System::Windows::Forms::DataGridView^ tblBorrowedEquipment;
	private: System::Windows::Forms::Button^ transactionApproveButton;
	private: System::Windows::Forms::Button^ transactionDenyButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ allTransactionsPanel;
	private: System::Windows::Forms::DataGridView^ tblAllTransactions;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ transactionsToDate;

	private: System::Windows::Forms::DateTimePicker^ transactionsFromDate;






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
			this->transactionsHomeButton = (gcnew System::Windows::Forms::Button());
			this->tblTransactions = (gcnew System::Windows::Forms::DataGridView());
			this->tblBorrowedEquipment = (gcnew System::Windows::Forms::DataGridView());
			this->transactionApproveButton = (gcnew System::Windows::Forms::Button());
			this->transactionDenyButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->allTransactionsPanel = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->transactionsToDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->transactionsFromDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->tblAllTransactions = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblTransactions))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblBorrowedEquipment))->BeginInit();
			this->allTransactionsPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblAllTransactions))->BeginInit();
			this->SuspendLayout();
			// 
			// transactionsHomeButton
			// 
			this->transactionsHomeButton->Location = System::Drawing::Point(12, 12);
			this->transactionsHomeButton->Name = L"transactionsHomeButton";
			this->transactionsHomeButton->Size = System::Drawing::Size(91, 44);
			this->transactionsHomeButton->TabIndex = 10;
			this->transactionsHomeButton->Text = L"HOME";
			this->transactionsHomeButton->UseVisualStyleBackColor = true;
			this->transactionsHomeButton->Click += gcnew System::EventHandler(this, &TransactionsPage::transactionsHomeButton_Click);
			// 
			// tblTransactions
			// 
			this->tblTransactions->AllowUserToAddRows = false;
			this->tblTransactions->AllowUserToDeleteRows = false;
			this->tblTransactions->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->tblTransactions->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->tblTransactions->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tblTransactions->Location = System::Drawing::Point(12, 82);
			this->tblTransactions->Name = L"tblTransactions";
			this->tblTransactions->ReadOnly = true;
			this->tblTransactions->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->tblTransactions->Size = System::Drawing::Size(309, 301);
			this->tblTransactions->TabIndex = 11;
			// 
			// tblBorrowedEquipment
			// 
			this->tblBorrowedEquipment->AllowUserToAddRows = false;
			this->tblBorrowedEquipment->AllowUserToDeleteRows = false;
			this->tblBorrowedEquipment->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->tblBorrowedEquipment->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->tblBorrowedEquipment->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tblBorrowedEquipment->Location = System::Drawing::Point(337, 82);
			this->tblBorrowedEquipment->Name = L"tblBorrowedEquipment";
			this->tblBorrowedEquipment->ReadOnly = true;
			this->tblBorrowedEquipment->Size = System::Drawing::Size(915, 587);
			this->tblBorrowedEquipment->TabIndex = 14;
			// 
			// transactionApproveButton
			// 
			this->transactionApproveButton->BackColor = System::Drawing::Color::Lime;
			this->transactionApproveButton->Location = System::Drawing::Point(12, 389);
			this->transactionApproveButton->Name = L"transactionApproveButton";
			this->transactionApproveButton->Size = System::Drawing::Size(150, 54);
			this->transactionApproveButton->TabIndex = 15;
			this->transactionApproveButton->Text = L"APPROVE";
			this->transactionApproveButton->UseVisualStyleBackColor = false;
			this->transactionApproveButton->Click += gcnew System::EventHandler(this, &TransactionsPage::transactionApproveButton_Click);
			// 
			// transactionDenyButton
			// 
			this->transactionDenyButton->BackColor = System::Drawing::Color::Red;
			this->transactionDenyButton->Location = System::Drawing::Point(168, 389);
			this->transactionDenyButton->Name = L"transactionDenyButton";
			this->transactionDenyButton->Size = System::Drawing::Size(153, 54);
			this->transactionDenyButton->TabIndex = 16;
			this->transactionDenyButton->Text = L"DENY";
			this->transactionDenyButton->UseVisualStyleBackColor = false;
			this->transactionDenyButton->Click += gcnew System::EventHandler(this, &TransactionsPage::transactionDenyButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(127, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 44);
			this->button1->TabIndex = 17;
			this->button1->Text = L"VIEW PENDING TRANSACTIONS";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TransactionsPage::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(337, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(194, 44);
			this->button2->TabIndex = 18;
			this->button2->Text = L"VIEW ALL TRANSACTIONS";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TransactionsPage::button2_Click);
			// 
			// allTransactionsPanel
			// 
			this->allTransactionsPanel->Controls->Add(this->button3);
			this->allTransactionsPanel->Controls->Add(this->label2);
			this->allTransactionsPanel->Controls->Add(this->label1);
			this->allTransactionsPanel->Controls->Add(this->transactionsToDate);
			this->allTransactionsPanel->Controls->Add(this->transactionsFromDate);
			this->allTransactionsPanel->Controls->Add(this->tblAllTransactions);
			this->allTransactionsPanel->Location = System::Drawing::Point(12, 82);
			this->allTransactionsPanel->Name = L"allTransactionsPanel";
			this->allTransactionsPanel->Size = System::Drawing::Size(1240, 587);
			this->allTransactionsPanel->TabIndex = 19;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(445, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(87, 44);
			this->button3->TabIndex = 20;
			this->button3->Text = L"EXPORT PDF";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &TransactionsPage::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label2->Location = System::Drawing::Point(226, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 13);
			this->label2->TabIndex = 24;
			this->label2->Text = L"To:";
			this->label2->Click += gcnew System::EventHandler(this, &TransactionsPage::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(11, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 23;
			this->label1->Text = L"From:";
			this->label1->Click += gcnew System::EventHandler(this, &TransactionsPage::label1_Click);
			// 
			// transactionsToDate
			// 
			this->transactionsToDate->Location = System::Drawing::Point(229, 30);
			this->transactionsToDate->Name = L"transactionsToDate";
			this->transactionsToDate->Size = System::Drawing::Size(193, 20);
			this->transactionsToDate->TabIndex = 22;
			this->transactionsToDate->ValueChanged += gcnew System::EventHandler(this, &TransactionsPage::transactionsTo_ValueChanged);
			// 
			// transactionsFromDate
			// 
			this->transactionsFromDate->Location = System::Drawing::Point(12, 30);
			this->transactionsFromDate->MinDate = System::DateTime(2020, 1, 4, 0, 0, 0, 0);
			this->transactionsFromDate->Name = L"transactionsFromDate";
			this->transactionsFromDate->Size = System::Drawing::Size(200, 20);
			this->transactionsFromDate->TabIndex = 21;
			this->transactionsFromDate->Value = System::DateTime(2024, 11, 2, 11, 7, 56, 0);
			this->transactionsFromDate->ValueChanged += gcnew System::EventHandler(this, &TransactionsPage::borrowFrom_ValueChanged);
			// 
			// tblAllTransactions
			// 
			this->tblAllTransactions->AllowUserToAddRows = false;
			this->tblAllTransactions->AllowUserToDeleteRows = false;
			this->tblAllTransactions->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->tblAllTransactions->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->tblAllTransactions->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tblAllTransactions->Location = System::Drawing::Point(3, 56);
			this->tblAllTransactions->Name = L"tblAllTransactions";
			this->tblAllTransactions->ReadOnly = true;
			this->tblAllTransactions->Size = System::Drawing::Size(1234, 531);
			this->tblAllTransactions->TabIndex = 20;
			this->tblAllTransactions->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TransactionsPage::tblAllTransactions_CellContentClick);
			// 
			// TransactionsPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->allTransactionsPanel);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->transactionDenyButton);
			this->Controls->Add(this->transactionApproveButton);
			this->Controls->Add(this->tblBorrowedEquipment);
			this->Controls->Add(this->tblTransactions);
			this->Controls->Add(this->transactionsHomeButton);
			this->Name = L"TransactionsPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EECE Inventory Tracker";
			this->Load += gcnew System::EventHandler(this, &TransactionsPage::TransactionsPage_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblTransactions))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblBorrowedEquipment))->EndInit();
			this->allTransactionsPanel->ResumeLayout(false);
			this->allTransactionsPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblAllTransactions))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Data::DataTable^ transactionsDataTable; //Needed to create dataTable object.
	private: System::Data::DataTable^ borrowedEquipmentDataTable;

	private: System::Void transactionsHomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		mainPage->Show();
	}
	private: System::Void TransactionsPage_Load(System::Object^ sender, System::EventArgs^ e) {
		allTransactionsPanel->Hide(); //Hide All Transactions Panel

		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection sqlConn(connString);
		try {
			sqlConn.Open();

			//Load Transactions
			SqlCommand^ cmdTransactions = gcnew SqlCommand("SELECT DISTINCT transactionID, studentID, transactionDate, status FROM borrowedEquipment WHERE status = 'Pending' ORDER BY transactionID ASC", % sqlConn);
			SqlDataAdapter^ adapterTransactions = gcnew SqlDataAdapter(cmdTransactions);
			transactionsDataTable = gcnew DataTable();
			adapterTransactions->Fill(transactionsDataTable);
			tblTransactions->DataSource = transactionsDataTable;

			//Checks if tblTransactions has any row
			if (tblTransactions->Rows->Count > 0) {
				int transactionID = Convert::ToInt32(tblTransactions->Rows[0]->Cells["transactionID"]->Value);

				//Load Equipment From Transactions
				SqlCommand^ cmdEquipment = gcnew SqlCommand("SELECT * from borrowedEquipment WHERE transactionID = @transactionID", % sqlConn);
				cmdEquipment->Parameters->AddWithValue("@transactionID", transactionID);
				SqlDataAdapter^ adapterEquipment = gcnew SqlDataAdapter(cmdEquipment);
				borrowedEquipmentDataTable = gcnew DataTable();
				adapterEquipment->Fill(borrowedEquipmentDataTable);
				tblBorrowedEquipment->DataSource = borrowedEquipmentDataTable;
			}
			//Loads empty tables.
			else {
				borrowedEquipmentDataTable = gcnew DataTable();
				tblBorrowedEquipment->DataSource = borrowedEquipmentDataTable;
			}

			sqlConn.Close();
		}
		catch (SqlException^ ex) {
			MessageBox::Show("Failed to Read Data: " + ex->Message);
		}


	}
	private: System::Void transactionDenyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection sqlConn(connString);

		if (tblBorrowedEquipment->Rows->Count == 0) {
			MessageBox::Show("There are no transactions to deny.", "Transaction Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			sqlConn.Open();

			int transactionID = Convert::ToInt32(tblTransactions->Rows[0]->Cells["transactionID"]->Value);
			String^ updateStatusQuery = "UPDATE borrowedEquipment SET status = 'Denied' WHERE transactionID = @transactionID";
			SqlCommand^ cmdUpdateStatus = gcnew SqlCommand(updateStatusQuery, % sqlConn);
			cmdUpdateStatus->Parameters->AddWithValue("@transactionID", transactionID);
			cmdUpdateStatus->ExecuteNonQuery();

			MessageBox::Show("Transaction denied successfully.");

			//Log Deny Activity
			String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
			SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, %sqlConn);
			activityCMD->Parameters->AddWithValue("@act", "Transaction Denied");
			activityCMD->Parameters->AddWithValue("@id", faculty->facultyNumber);
			activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));
			activityCMD->ExecuteNonQuery();

			// Refresh the DataGridViews
			TransactionsPage_Load(sender, e);

			sqlConn.Close();
		}
		catch (SqlException^ ex) {
			MessageBox::Show("Error denying request." + ex->Message);
		}
	}

private: System::Void transactionApproveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);

	if (tblBorrowedEquipment->Rows->Count == 0) {
		MessageBox::Show("There are no transactions to approve.", "Transaction Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	try {
		sqlConn.Open();
		for (int i = 0; i < tblBorrowedEquipment->Rows->Count; i++) {
			int requestedQuantity = Convert::ToInt32(tblBorrowedEquipment->Rows[i]->Cells["equipmentStock"]->Value);
			int requestedID = Convert::ToInt32(tblBorrowedEquipment->Rows[i]->Cells["equipmentID"]->Value);

			String^ updateStockQuery = "UPDATE equipment SET stock = stock - @requestedQuantity WHERE equipmentID = @equipmentID";
			SqlCommand^ cmdUpdateStock = gcnew SqlCommand(updateStockQuery, % sqlConn);
			cmdUpdateStock->Parameters->AddWithValue("@requestedQuantity", requestedQuantity);
			cmdUpdateStock->Parameters->AddWithValue("@equipmentID", requestedID);
			cmdUpdateStock->ExecuteNonQuery();
		}

		int transactionID = Convert::ToInt32(tblTransactions->Rows[0]->Cells["transactionID"]->Value);
		String^ updateStatusQuery = "UPDATE borrowedEquipment SET status = 'Approved' WHERE transactionID = @transactionID";
		SqlCommand^ cmdUpdateStatus = gcnew SqlCommand(updateStatusQuery, % sqlConn);
		cmdUpdateStatus->Parameters->AddWithValue("@transactionID", transactionID);
		cmdUpdateStatus->ExecuteNonQuery();

		

		MessageBox::Show("Transaction approved and stock updated successfully.");

		//Log Deny Activity
		String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
		SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, % sqlConn);
		activityCMD->Parameters->AddWithValue("@act", "Transaction Approved");
		activityCMD->Parameters->AddWithValue("@id", faculty->facultyNumber);
		activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));
		activityCMD->ExecuteNonQuery();

		// Refresh the DataGridViews
		TransactionsPage_Load(sender, e);

		sqlConn.Close();
	}
	catch (SqlException^ ex) {	
		MessageBox::Show("Error updating stock values." + ex->Message);
	}
	
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	allTransactionsPanel->Hide();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ transactionsFrom = transactionsFromDate->Value.ToString("MM-dd-yyyy");
	String^ transactionsTo = transactionsToDate->Value.ToString("MM-dd-yyyy");
	allTransactionsPanel->Show();
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);
	try {
		sqlConn.Open();
		String^ query = "SELECT * from borrowedEquipment WHERE equipmentBorrowFrom >= @fromDate AND equipmentBorrowTo <= @toDate";
		SqlCommand^ cmd = gcnew SqlCommand(query, %sqlConn);
		cmd->Parameters->AddWithValue("@fromDate", transactionsFrom);
		cmd->Parameters->AddWithValue("@toDate", transactionsTo);
		//Load Transactions
		SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
		transactionsDataTable = gcnew DataTable();
		adapter->Fill(transactionsDataTable);
		tblAllTransactions->DataSource = transactionsDataTable;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error loading all transactions" + ex->Message);
	}
}
private: System::Void borrowFrom_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	transactionsToDate->MinDate = transactionsFromDate->Value;
	String^ transactionsFrom = transactionsFromDate->Value.ToString("MM-dd-yyyy");
	String^ transactionsTo = transactionsToDate->Value.ToString("MM-dd-yyyy");
	allTransactionsPanel->Show();
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);
	try {
		sqlConn.Open();
		String^ query = "SELECT * from borrowedEquipment WHERE equipmentBorrowFrom >= @fromDate AND equipmentBorrowTo <= @toDate";
		SqlCommand^ cmd = gcnew SqlCommand(query, % sqlConn);
		cmd->Parameters->AddWithValue("@fromDate", transactionsFrom);
		cmd->Parameters->AddWithValue("@toDate", transactionsTo);
		//Load Transactions
		SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
		transactionsDataTable = gcnew DataTable();
		adapter->Fill(transactionsDataTable);
		tblAllTransactions->DataSource = transactionsDataTable;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error loading all transactions" + ex->Message);
	}
}
private: System::Void transactionsTo_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ transactionsFrom = transactionsFromDate->Value.ToString("MM-dd-yyyy");
	String^ transactionsTo = transactionsToDate->Value.ToString("MM-dd-yyyy");
	allTransactionsPanel->Show();
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	SqlConnection sqlConn(connString);
	try {
		sqlConn.Open();
		String^ query = "SELECT * from borrowedEquipment WHERE equipmentBorrowFrom >= @fromDate AND equipmentBorrowTo <= @toDate";
		SqlCommand^ cmd = gcnew SqlCommand(query, % sqlConn);
		cmd->Parameters->AddWithValue("@fromDate", transactionsFrom);
		cmd->Parameters->AddWithValue("@toDate", transactionsTo);
		//Load Transactions
		SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
		transactionsDataTable = gcnew DataTable();
		adapter->Fill(transactionsDataTable);
		tblAllTransactions->DataSource = transactionsDataTable;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error loading all transactions" + ex->Message);
	}
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
		String^ fileName = "Transactions.pdf"; // Change this to whatever file name you want
		return folderPath + "\\" + fileName;
	}

	// If no folder was selected, return nullptr
	return nullptr;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ filePath = getFilePath();

	// Check if a valid file path was selected
	if (filePath != nullptr) {
		ExportDataGridViewToPdf(tblAllTransactions, filePath);
		MessageBox::Show("File saved at: " + filePath);

		//Log Export PDF Activity
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();
		String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
		SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, sqlConn);
		activityCMD->Parameters->AddWithValue("@act", "Export Transactions PDF");
		activityCMD->Parameters->AddWithValue("@id", faculty->facultyNumber);
		activityCMD->Parameters->AddWithValue("@time", DateTime::Now.ToString("MM-dd-yyyy HH:mm"));
		activityCMD->ExecuteNonQuery();
		sqlConn->Close();
	}
	else {
		MessageBox::Show("No folder selected.");
	}

}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tblAllTransactions_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
