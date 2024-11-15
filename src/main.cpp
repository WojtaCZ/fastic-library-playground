#include "main.hpp"
#include "aurora.hpp"
#include "sample_databuff.hpp"
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <string>
#include <chrono>

#include <bitset>

aurora::rx fastic1(auroraData, 1024);
uint64_t scrambler = 0, output = 0;

int main(int argc, char* argv[]){

	if(!fastic1.synchronize()){
		std::cout << "Failed to synchronize the receiver\n";
		return -1;
	}else{
		std::cout << "Synced with bitslip " << unsigned(fastic1.getBitSlip()) << "\n"; 
	}

	//fastic1.calculateBitSlipTest();

	auto dataOld = fastic1.getPacketData(5);
	auto dataNew = fastic1.getPacketData(6);

	/*scrambler = data1 << 1;


		output = 0;

        for(int i = 63; i >= 0; i--){
            uint8_t newBit = ((data2 >> i) & 1);
            //Shift the latest bit to the scrambler buffer
            scrambler |= newBit;
            output |= ((scrambler >> 0) & 1) ^ ((scrambler >> 39) & 1) ^ ((scrambler >> 58) & 1)
            
            scrambler <<= 1;
            if(i != 0) output <<= 1;

        }*/
	



	auto data = fastic1.descramblePacketData(dataNew, dataOld);

	
	/*fastic1.processBuffer(true);
	auto packets = fastic1.getPacketBuffer();

	

	for(auto packet : packets){
		if(packet.getType() != aurora::packet::type::error){
			std::cout << "Type: " << std::string((packet.getType() == aurora::packet::type::data) ? "data   " : "control") << " Data: " << std::hex << packet.getData() << "\n";
		}else{
			std::cout << "Type: " << "error\n";
		} 

	}

	std::cout << "\nStatistics" << std::dec << std::setw(6) << std::setfill(' ') 
			  << "\n  Data bitslip:         " << std::setw(6) << std::setfill(' ') << unsigned(fastic1.getBitSlip())
			  << "\n  Packet buffer size:   " << std::setw(6) << std::setfill(' ') << packets.size()
			  << "\n  Packet buffer errors: " << std::setw(6) << std::setfill(' ') << std::count_if(packets.begin(), packets.end(), [](aurora::packet packet) { return (packet.getType() == aurora::packet::type::error); })
			  << "\n  Error frames overall: " << std::setw(6) << std::setfill(' ') << std::setprecision(3) << fastic1.getBER()*100 << " %";
	*/
}






