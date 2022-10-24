#include <stdio.h>


int main()
{

  int deviceId;
  cudaGetDevice(&deviceId);

  cudaDeviceProp props;
  cudaGetDeviceProperties(&props, deviceId);


  int computeCapabilityMajor = props.major;
  int computeCapabilityMinor = props.minor;
  int multiProcessorCount = props.multiProcessorCount;
  int warpSize = props.warpSize;

  printf("  Device ID: %d\n   Number of SMs: %d\n   Compute Capability Major: %d\n   Compute Capability Minor: %d\n   Warp Size: %d\n",   deviceId,  multiProcessorCount,    computeCapabilityMajor,    computeCapabilityMinor,    warpSize);


}


