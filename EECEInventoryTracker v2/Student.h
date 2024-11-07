#pragma once

using namespace System;


//Initializes Class Student. Each variable is from the table students in EECEInventoryTracker DB
public ref class Student {

public:
	int id;
	String^ studentNumber;
	String^ name;
	String^ program;
	String^ contactInfo;
	String^ email;
	String^ password;
};