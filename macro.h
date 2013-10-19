#ifndef MACRO_H
#define MACRO_H

#include <string>

//#define INST ;

//#define DEBUGCPU
//#define DEBUGGPU

#define cpu_message(message) std::cerr << "(CPU) " << message << std::endl;
#define gpu_message(message) std::cerr << "(GPU) " << message << std::endl;

#ifdef DEBUGCPU
# define INST cpu_message(std::hex << "Instruction " << (int)PC << " - " << std::string(typeid(*this).name()).substr(1) << " - " <<  __func__);
# define cpum(message) cpu_message(message)
#else
# define cpum(message) ;
# define INST ;
#endif

#ifdef DEBUGGPU
# define gpum(message) gpu_message(message)
#else
# define gpum(message) ;
#endif

// #define INST if (std::string(typeid(*this).name()).substr(1) == "Loads") cpu_message(std::hex << "Instruction " << (int)PC << " - " << std::string(typeid(*this).name()).substr(1) << " - " <<  __func__);


#endif // MACRO_H
