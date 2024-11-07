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
	/// Summary for ActivityPage
	/// </summary>
	public ref class ActivityPage : public System::Windows::Forms::Form
	{
	public:
		Form^ mainPage;
		Faculty^ faculty;
		ActivityPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ActivityPage(Faculty^ facultyL, Form^ formL)
		{
			InitializeComponent();
			faculty = facultyL;
			mainPage = formL;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ActivityPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ transactionsHomeButton;
	protected:
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ activityToDate;

	private: System::Windows::Forms::DateTimePicker^ activityFromDate;

	private: System::Windows::Forms::DataGridView^ tblActivity;

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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->activityToDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->activityFromDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->tblActivity = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblActivity))->BeginInit();
			this->SuspendLayout();
			// 
			// transactionsHomeButton
			// 
			this->transactionsHomeButton->Location = System::Drawing::Point(24, 8);
			this->transactionsHomeButton->Name = L"transactionsHomeButton";
			this->transactionsHomeButton->Size = System::Drawing::Size(91, 44);
			this->transactionsHomeButton->TabIndex = 25;
			this->transactionsHomeButton->Text = L"HOME";
			this->transactionsHomeButton->UseVisualStyleBackColor = true;
			this->transactionsHomeButton->Click += gcnew System::EventHandler(this, &ActivityPage::transactionsHomeButton_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(457, 50);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(87, 44);
			this->button3->TabIndex = 26;
			this->button3->Text = L"EXPORT PDF";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ActivityPage::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label2->Location = System::Drawing::Point(238, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 13);
			this->label2->TabIndex = 31;
			this->label2->Text = L"To:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(23, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 30;
			this->label1->Text = L"From:";
			// 
			// activityToDate
			// 
			this->activityToDate->Location = System::Drawing::Point(241, 74);
			this->activityToDate->Name = L"activityToDate";
			this->activityToDate->Size = System::Drawing::Size(193, 20);
			this->activityToDate->TabIndex = 29;
			this->activityToDate->ValueChanged += gcnew System::EventHandler(this, &ActivityPage::activityToDate_ValueChanged);
			// 
			// activityFromDate
			// 
			this->activityFromDate->Location = System::Drawing::Point(24, 74);
			this->activityFromDate->MinDate = System::DateTime(2020, 1, 4, 0, 0, 0, 0);
			this->activityFromDate->Name = L"activityFromDate";
			this->activityFromDate->Size = System::Drawing::Size(200, 20);
			this->activityFromDate->TabIndex = 28;
			this->activityFromDate->Value = System::DateTime(2024, 11, 2, 11, 7, 56, 0);
			this->activityFromDate->ValueChanged += gcnew System::EventHandler(this, &ActivityPage::transactionsFromDate_ValueChanged);
			// 
			// tblActivity
			// 
			this->tblActivity->AllowUserToAddRows = false;
			this->tblActivity->AllowUserToDeleteRows = false;
			this->tblActivity->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tblActivity->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->tblActivity->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tblActivity->Location = System::Drawing::Point(24, 100);
			this->tblActivity->Name = L"tblActivity";
			this->tblActivity->ReadOnly = true;
			this->tblActivity->Size = System::Drawing::Size(1228, 531);
			this->tblActivity->TabIndex = 27;
			// 
			// ActivityPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->transactionsHomeButton);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->activityToDate);
			this->Controls->Add(this->activityFromDate);
			this->Controls->Add(this->tblActivity);
			this->Name = L"ActivityPage";
			this->Text = L"EECE Inventory Tracker";
			this->Load += gcnew System::EventHandler(this, &ActivityPage::ActivityPage_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblActivity))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: DataTable^ activityDataTable = gcnew DataTable();
	private: System::Void transactionsHomeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		mainPage->Show();
	}
private: System::Void transactionsFromDate_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	activityToDate->MinDate = activityFromDate->Value;
	ActivityPage_Load(sender, e);
}
private: System::Void ActivityPage_Load(System::Object^ sender, System::EventArgs^ e) {
	activityToDate->MinDate = activityToDate->Value;
	String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
	String^ activityFromDateStr = activityFromDate->Value.ToString("MM-dd-yyyy HH:mm");
	String^ activityToDateStr = activityToDate->Value.ToString("MM-dd-yyyy HH:mm");
	SqlConnection sqlConn(connString);
	try {
		sqlConn.Open();

		//Load Transactions
		SqlCommand^ cmdTransactions = gcnew SqlCommand("SELECT * from activity WHERE Time >= @time AND Time <= @timeafter", % sqlConn);
		cmdTransactions->Parameters->AddWithValue("@time", activityFromDateStr);
		cmdTransactions->Parameters->AddWithValue("@timeafter", activityToDateStr);
		SqlDataAdapter^ adapterActivity = gcnew SqlDataAdapter(cmdTransactions);
		activityDataTable = gcnew DataTable();
		adapterActivity->Fill(activityDataTable);
		tblActivity->DataSource = activityDataTable;
	}
	catch (SqlException^ ex) {
		MessageBox::Show("Failed to Read Data: " + ex->Message);
	}
	finally {
		sqlConn.Close();
	}
}
private: System::Void activityToDate_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	ActivityPage_Load(sender, e);
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
			   String^ fileName = "Activity.pdf"; // Change this to whatever file name you want
			   return folderPath + "\\" + fileName;
		   }

		   // If no folder was selected, return nullptr
		   return nullptr;
	   }
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ filePath = getFilePath();

	// Check if a valid file path was selected
	if (filePath != nullptr) {
		ExportDataGridViewToPdf(tblActivity, filePath);
		MessageBox::Show("File saved at: " + filePath);

		//Log Export PDF Activity
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=EECEInventoryTracker;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();
		String^ activityQuery = "INSERT INTO activity (Activity, UserID, Time) VALUES (@act, @id, @time)";
		SqlCommand^ activityCMD = gcnew SqlCommand(activityQuery, sqlConn);
		activityCMD->Parameters->AddWithValue("@act", "Export Activity PDF");
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
