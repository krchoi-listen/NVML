#include <unistd.h>

#include "GpuQuery.h"

int main()
{
//	int i;
	GpuQuery * tQuery;

	tQuery = new GpuQuery();

	if (tQuery->InitializeQuery() == 0)
	{
		tQuery->PrintErrorString("Initialization Failed");
		return 0;
	}

	tQuery->GetDevices();
	tQuery->GetDeviceNames();
	tQuery->GetAccountingModes();
//	tQuery->PrintAllDeviceInfo();

	tQuery->EnableAccountingModes(NVML_FEATURE_ENABLED);
	tQuery->GetAccountingModes();
	tQuery->ClearAccountingPids();
//	tQuery->PrintAllDeviceInfo();

//	for (i = 0; i < 100; i++)
	while(true)
	{	
		tQuery->GetAccountingPids();
		tQuery->GetAccountingStats();
		tQuery->PrintAllDeviceInfo();
		tQuery->ClearAccountingPids();
		usleep(100000);
	}

//	tQuery->EnableAccountingModes(NVML_FEATURE_DISABLED);
//	tQuery->GetAccountingModes();
//	tQuery->PrintAllDeviceInfo();

	tQuery->ShutdownNVML();
}

