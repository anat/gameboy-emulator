#ifndef __CPU_H__
#define __CPU_H__

#include <typeinfo>
#include <stdint.h>
#include <iomanip>
#include "macro.h"
#include "Memory.h"
#include "Interruption.h"
#include "ALU.h"
#include "Loads.h"
#include "Jumps.h"
#include "BitInstruction.h"

using namespace std;

class CPU;

typedef void (CPU::*instruction)();

class CPU : public ALU, public Loads, public Jumps, public Interruption//, public BitInstruction
{
private:
    uint8_t *memory;

public:
    instruction instructions[0xFF];
    CPU() : memory(Memory::GetInstance()->memory)
    {
        this->initInstructions();
    }

    void run();

    void initInstructions()
    {
        memset(this->instructions, 0, sizeof(instructions));
        this->initALU();
        this->instructions[0x00] = &CPU::nop;

        this->instructions[0xe5] = &CPU::pushHL;
        this->instructions[0xcd] = &CPU::call1;
        this->instructions[0xc9] = &CPU::RET;

        this->instructions[0x10] = &CPU::STOP;

        // Register Loads
        this->instructions[0x70] = &CPU::LDHLB;
        this->instructions[0x71] = &CPU::LDHLC;
        this->instructions[0x72] = &CPU::LDHLD;
        this->instructions[0x73] = &CPU::LDHLE;
        this->instructions[0x74] = &CPU::LDHLH;
        this->instructions[0x75] = &CPU::LDHLL;
        this->instructions[0x36] = &CPU::LDHLN;

        // Jumps
        this->instructions[0xc3] = &CPU::JP;
        this->instructions[0xc2] = &CPU::JPNZ;
        this->instructions[0xca] = &CPU::JPZ;
        this->instructions[0xd2] = &CPU::JPNC;
        this->instructions[0xda] = &CPU::JPC;

        // 8-bit Loads
        this->instructions[0x3e] = &CPU::LDA;
        this->instructions[0x06] = &CPU::LDB;
        this->instructions[0x0e] = &CPU::LDC;
        this->instructions[0x16] = &CPU::LDD;
        this->instructions[0x1e] = &CPU::LDE;
        this->instructions[0x26] = &CPU::LDH;
        this->instructions[0x2e] = &CPU::LDL;
        this->instructions[0x02] = &CPU::LDBCA;

        this->instructions[0x0a] = &CPU::LDABC;

        this->instructions[0x01] = &CPU::loadBC;
        this->instructions[0x11] = &CPU::loadDE;
        this->instructions[0x21] = &CPU::loadHL;
        this->instructions[0x31] = &CPU::loadSP;

        this->instructions[0x32] = &CPU::LDDHL;
        this->instructions[0x22] = &CPU::LDIHL;

        this->instructions[0x7f] = &CPU::LDAA;
        this->instructions[0x78] = &CPU::LDAB;
        this->instructions[0x79] = &CPU::LDAC;
        this->instructions[0x7a] = &CPU::LDAD;
        this->instructions[0x7b] = &CPU::LDAE;
        this->instructions[0x7c] = &CPU::LDAH;
        this->instructions[0x7d] = &CPU::LDAL;

        this->instructions[0x47] = &CPU::LDBA;
        this->instructions[0x40] = &CPU::LDBB;
        this->instructions[0x41] = &CPU::LDBC;
        this->instructions[0x42] = &CPU::LDBD;
        this->instructions[0x43] = &CPU::LDBE;
        this->instructions[0x44] = &CPU::LDBH;
        this->instructions[0x45] = &CPU::LDBL;

        this->instructions[0x4f] = &CPU::LDCA;
        this->instructions[0x48] = &CPU::LDCB;
        this->instructions[0x49] = &CPU::LDCC;
        this->instructions[0x4a] = &CPU::LDCD;
        this->instructions[0x4b] = &CPU::LDCE;
        this->instructions[0x4c] = &CPU::LDCH;
        this->instructions[0x4d] = &CPU::LDCL;

        this->instructions[0x57] = &CPU::LDDA;
        this->instructions[0x50] = &CPU::LDDB;
        this->instructions[0x51] = &CPU::LDDC;
        this->instructions[0x52] = &CPU::LDDD;
        this->instructions[0x53] = &CPU::LDDE;
        this->instructions[0x54] = &CPU::LDDH;
        this->instructions[0x55] = &CPU::LDDL;

        this->instructions[0x5f] = &CPU::LDEA;
        this->instructions[0x58] = &CPU::LDEB;
        this->instructions[0x59] = &CPU::LDEC;
        this->instructions[0x5A] = &CPU::LDED;
        this->instructions[0x5B] = &CPU::LDEE;
        this->instructions[0x5C] = &CPU::LDEH;
        this->instructions[0x5D] = &CPU::LDEL;

        this->instructions[0x67] = &CPU::LDHA;
        this->instructions[0x60] = &CPU::LDHB;
        this->instructions[0x61] = &CPU::LDHC;
        this->instructions[0x62] = &CPU::LDHD;
        this->instructions[0x63] = &CPU::LDHE;
        this->instructions[0x64] = &CPU::LDHH;
        this->instructions[0x65] = &CPU::LDHL;

        this->instructions[0x6F] = &CPU::LDLA;
        this->instructions[0x68] = &CPU::LDLB;
        this->instructions[0x69] = &CPU::LDLC;
        this->instructions[0x6A] = &CPU::LDLD;
        this->instructions[0x6B] = &CPU::LDLE;
        this->instructions[0x6C] = &CPU::LDLH;
        this->instructions[0x6D] = &CPU::LDLL;

        this->instructions[0xea] = &CPU::LDNA;
        this->instructions[0xe2] = &CPU::LDMCA;

        this->instructions[0x2a] = &CPU::LDIAHL;

        // Restarts
        /*
        this->instructions[0xc7] = &CPU::RST0;
        this->instructions[0xcf] = &CPU::RST8;
        this->instructions[0xd7] = &CPU::RST10;
        this->instructions[0xdf] = &CPU::RST18;
        this->instructions[0xe7] = &CPU::RST20;
        this->instructions[0xef] = &CPU::RST28;
        this->instructions[0xf7] = &CPU::RST30;
        this->instructions[0xff] = &CPU::RST38;
        */

        this->instructions[0x20] = &CPU::JR20;

        this->instructions[0x1f] = &CPU::RRA;
        this->instructions[0xfb] = &CPU::EI;
        this->instructions[0xf3] = &CPU::DI;

        this->instructions[0xe0] = &CPU::LDDHNA;
        this->instructions[0xf0] = &CPU::LDDHAN;

        this->instructions[0x2f] = &CPU::CPL;
    }

    void initALU()
    {
        // 8-bit ALU (page 80)
        this->instructions[0x87] = &CPU::ADDAA;
        this->instructions[0x80] = &CPU::ADDAB;
        this->instructions[0x81] = &CPU::ADDAC;
        this->instructions[0x82] = &CPU::ADDAD;
        this->instructions[0x83] = &CPU::ADDAE;
        this->instructions[0x84] = &CPU::ADDAH;
        this->instructions[0x85] = &CPU::ADDAL;
        this->instructions[0x86] = &CPU::ADDAHL;
        this->instructions[0xc6] = &CPU::ADDAN;

        this->instructions[0x8f] = &CPU::ADDCAA;
        this->instructions[0x88] = &CPU::ADDCAB;
        this->instructions[0x89] = &CPU::ADDCAC;
        this->instructions[0x8a] = &CPU::ADDCAD;
        this->instructions[0x8b] = &CPU::ADDCAE;
        this->instructions[0x8c] = &CPU::ADDCAH;
        this->instructions[0x8d] = &CPU::ADDCAL;
        //this->instructions[0x8e] = &CPU::ADDCAHL;
        //this->instructions[0xce] = &CPU::ADDCAN;

        this->instructions[0x97] = &CPU::SUBAA;
        this->instructions[0x90] = &CPU::SUBAB;
        this->instructions[0x91] = &CPU::SUBAC;
        this->instructions[0x92] = &CPU::SUBAD;
        this->instructions[0x93] = &CPU::SUBAE;
        this->instructions[0x94] = &CPU::SUBAH;
        this->instructions[0x95] = &CPU::SUBAL;
        //this->instructions[0x96] = &CPU::SUBAHL;
        //this->instructions[0xd6] = &CPU::SUBAN;

        this->instructions[0x9f] = &CPU::SUBACAA;
        this->instructions[0x98] = &CPU::SUBACAB;
        this->instructions[0x99] = &CPU::SUBACAC;
        this->instructions[0x9a] = &CPU::SUBACAD;
        this->instructions[0x9b] = &CPU::SUBACAE;
        this->instructions[0x9c] = &CPU::SUBACAH;
        this->instructions[0x9d] = &CPU::SUBACAL;
        //this->instructions[0x9e] = &CPU::SUBACAHL;
        //this->instructions[0xde] = &CPU::SUBACAN;

        this->instructions[0xa7] = &CPU::ANDAA;
        this->instructions[0xa0] = &CPU::ANDAB;
        this->instructions[0xa1] = &CPU::ANDAC;
        this->instructions[0xa2] = &CPU::ANDAD;
        this->instructions[0xa3] = &CPU::ANDAE;
        this->instructions[0xa4] = &CPU::ANDAH;
        this->instructions[0xa5] = &CPU::ANDAL;
        //this->instructions[0xa6] = &CPU::ANDAHL;
        this->instructions[0xe6] = &CPU::ANDAN;

        this->instructions[0xb7] = &CPU::ORAA;
        this->instructions[0xb0] = &CPU::ORAB;
        this->instructions[0xb1] = &CPU::ORAC;
        this->instructions[0xb2] = &CPU::ORAD;
        this->instructions[0xb3] = &CPU::ORAE;
        this->instructions[0xb4] = &CPU::ORAH;
        this->instructions[0xb5] = &CPU::ORAL;
        //this->instructions[0xb6] = &CPU::ORAHL;
        //this->instructions[0xf6] = &CPU::ORAN;

        this->instructions[0xaf] = &CPU::XORAA;
        this->instructions[0xa8] = &CPU::XORAB;
        this->instructions[0xa9] = &CPU::XORAC;
        this->instructions[0xaa] = &CPU::XORAD;
        this->instructions[0xab] = &CPU::XORAE;
        this->instructions[0xac] = &CPU::XORAH;
        this->instructions[0xad] = &CPU::XORAL;
        //this->instructions[0xae] = &CPU::XORAHL;
        //this->instructions[0xee] = &CPU::XORAN;

        this->instructions[0xbf] = &CPU::CPAA;
        this->instructions[0xb8] = &CPU::CPAB;
        this->instructions[0xb9] = &CPU::CPAC;
        this->instructions[0xba] = &CPU::CPAD;
        this->instructions[0xbb] = &CPU::CPAE;
        this->instructions[0xbc] = &CPU::CPAH;
        this->instructions[0xbd] = &CPU::CPAL;
        //this->instructions[0xbe] = &CPU::CPAHL;
        this->instructions[0xfe] = &CPU::CPAN;

        this->instructions[0x3C] = &CPU::INCA;
        this->instructions[0x04] = &CPU::INCB;
        this->instructions[0x0c] = &CPU::INCC;
        this->instructions[0x14] = &CPU::INCD;
        this->instructions[0x1c] = &CPU::INCE;
        this->instructions[0x24] = &CPU::INCH;
        this->instructions[0x2c] = &CPU::INCL;
        //this->instructions[0x34] = &CPU::INCHL;

        this->instructions[0x3d] = &CPU::DECA;
        this->instructions[0x05] = &CPU::DECB;
        this->instructions[0x0d] = &CPU::DECC;
        this->instructions[0x15] = &CPU::DECD;
        this->instructions[0x1d] = &CPU::DECE;
        this->instructions[0x25] = &CPU::DECH;
        this->instructions[0x2d] = &CPU::DECL;
        //this->instructions[0x35] = &CPU::DECHL;

        // 16-bit ALU (page 90)

        //this->instructions[0x09] = &CPU::ADDHLBC;
        //this->instructions[0x19] = &CPU::ADDHLDE;
        //this->instructions[0x29] = &CPU::ADDHLHL;
        //this->instructions[0x39] = &CPU::ADDHLSP;

        //this->instructions[0xe8] = &CPU::ADDSPN;

        this->instructions[0x03] = &CPU::INCBC;
        this->instructions[0x13] = &CPU::INCDE;
        this->instructions[0x23] = &CPU::INCHL;
        this->instructions[0x33] = &CPU::INCSP;

        this->instructions[0x0b] = &CPU::DECBC;
        this->instructions[0x1b] = &CPU::DECDE;
        this->instructions[0x2b] = &CPU::DECHL;
        this->instructions[0x3b] = &CPU::DECSP;
    }

    void db()
    {
        cpum(endl
             << "----------------------------------------------------------");
        cpum("PC = " << PC);
        cpum("----------------------------------------------------------");
        for (int i = 0; i < 10; i++)
        {
            for (int j = i * 10; j < (10 * i) + 10; j++)
            {
                //cpum("J=" << j << " ")
                cout << setfill('0') << setw(2) << hex << (short)memory[PC + j] << " ";
            }
            cpum("");
        }
        cpum("----------------------------------------------------------");
    }

    void dbr()
    {
        cpum("A = " << A << " B = " << B << " C = " << C << " D = " << D << " E = " << E << " H = " << H << " L = " << L << " Z = " << (int)Z)
        // if (Z == 1) read(0, 0, 1);
    }

    void nop()
    {
        INST PC += 1;
        cpum("nop")
    }

    void pushHL()
    {
        INST this->memory[--SP] = this->H;
        this->memory[--SP] = this->L;
        cpum("Push HL")
            PC++;
    }

    /*
    void RST0() {INST RST(0x00); }
    void RST8() {INST RST(0x08); }
    void RST10() {INST RST(0x10); }
    void RST18() {INST RST(0x18); }
    void RST20() {INST RST(0x20); }
    void RST28() {INST RST(0x28); }
    void RST30() {INST RST(0x30); }
    void RST38() {INST RST(0x38); }
*/

    void STOP()
    {
        INST PC++;
        std::cout << "STOP" << std::endl;
    }
    void RST(uint8_t n)
    {
        INST PC++;
        return;
        SP -= 2;
        memory[SP] = PC;
        PC = n;
    }

    void RRA()
    {
        INST A >>= 1;
        A |= (this->CA << 7);
        if (!A)
            Z = 1;
        else
            Z = 0;
        PC++;
    }
    void CPL()
    {
        setN();
        setH();
        A = ~A;
        PC++;
    }
};// __attribute__((packed));

#endif
