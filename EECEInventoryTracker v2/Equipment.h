#pragma once

using namespace System;

//Initializes Class Equipment. Each variable is from the table equipments in EECEInventoryTracker DB
public ref class Equipment {

public:
	int equipmentID;
	String^ equipmentName;
	String^ equipmentDesc;
	int equipmentStock;
};