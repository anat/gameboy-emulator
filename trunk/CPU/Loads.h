#ifndef LOADS_H
#define LOADS_H

#include "CPU.h"
#include "Register.h"
#include "Memory.h"

class Loads : virtual public Register
{
public:
    uint8_t* memory;
    Loads()
    {
        memory = Memory::GetInstance()->memory;
    }

    // LD 8 bit
    void LDA() {INST  A = memory[PC + 1]; PC += 2; cpum("load A : A = " << (int)A) }
    void LDB() {INST  B = memory[PC + 1]; PC += 2; cpum("load B : B = " << (int)B) }
    void LDC() {INST  C = memory[PC + 1]; PC += 2; cpum("load C : C = " << (int)C) }
    void LDD() {INST  D = memory[PC + 1]; PC += 2; cpum("load D : D = " << (int)D) }
    void LDE() {INST  E = memory[PC + 1]; PC += 2; cpum("load E : E = " << (int)E) }
    void LDH() {INST  H = memory[PC + 1]; PC += 2; cpum("load H : H = " << (int)H) }
    void LDL() {INST  L = memory[PC + 1]; PC += 2; cpum("load L : L = " << (int)L) }

    // Load register
    void LDHLB() {INST  memory[(H << 8) + L] = B; PC++; }
    void LDHLC() {INST  memory[(H << 8) + L] = C; PC++; }
    void LDHLD() {INST  memory[(H << 8) + L] = D; PC++; }
    void LDHLE() {INST  memory[(H << 8) + L] = E; PC++; }
    void LDHLH() {INST  memory[(H << 8) + L] = H; PC++; }
    void LDHLL() {INST  memory[(H << 8) + L] = L; PC++; }
    void LDHLN() {INST  memory[(H << 8) + L] = N; PC += 2; }


    void LDAA() {INST  ; PC++; cpum("Load A = A") }
    void LDAB() {INST  A = B; PC++; cpum("Load A = B " << " A = " << A) }
    void LDAC() {INST  A = C; PC++; cpum("Load A = C " << " A = " << A) }
    void LDAD() {INST  A = D; PC++; cpum("Load A = D " << " A = " << A) }
    void LDAE() {INST  A = E; PC++; cpum("Load A = E " << " A = " << A) }
    void LDAH() {INST  A = H; PC++; cpum("Load A = H " << " A = " << A) }
    void LDAL() {INST  A = L; PC++; cpum("Load A = L " << " A = " << A) }

    void LDBA() {INST  B = A; PC++; cpum("Load B = A " << " B = " << B) }
    void LDBB() {INST  ; PC++; cpum("Load B = B " << " B = " << B) }
    void LDBC() {INST  B = C; PC++; cpum("Load B = C " << " B = " << B) }
    void LDBD() {INST  B = D; PC++; cpum("Load B = D " << " B = " << B) }
    void LDBE() {INST  B = E; PC++; cpum("Load B = E " << " B = " << B) }
    void LDBH() {INST  B = H; PC++; cpum("Load B = H " << " B = " << B) }
    void LDBL() {INST  B = L; PC++; cpum("Load B = L " << " B = " << B) }

    void LDCA() {INST  C = A; PC++; cpum("Load C = A " << " C = " << C) }
    void LDCB() {INST  C = B; PC++; cpum("Load C = B " << " C = " << C) }
    void LDCC() {INST  ; PC++; cpum("Load C = C " << " C = " << C) }
    void LDCD() {INST  C = D; PC++; cpum("Load C = D " << " C = " << C) }
    void LDCE() {INST  C = E; PC++; cpum("Load C = E " << " C = " << C) }
    void LDCH() {INST  C = H; PC++; cpum("Load C = H " << " C = " << C) }
    void LDCL() {INST  C = L; PC++; cpum("Load C = L " << " C = " << C) }

    void LDDA() {INST  D = A; PC++; cpum("Load D = A " << " D = " << D) }
    void LDDB() {INST  D = B; PC++; cpum("Load D = B " << " D = " << D) }
    void LDDC() {INST  D = C; PC++; cpum("Load D = C " << " D = " << D) }
    void LDDD() {INST  ; PC++; cpum("Load D = D " << " D = " << D) }
    void LDDE() {INST  D = E; PC++; cpum("Load D = E " << " D = " << D) }
    void LDDH() {INST  D = H; PC++; cpum("Load D = H " << " D = " << D) }
    void LDDL() {INST  D = L; PC++; cpum("Load D = L " << " D = " << D) }

    void LDEA() {INST  E = A; PC++; cpum("Load E = A " << " E = " << E) }
    void LDEB() {INST  E = B; PC++; cpum("Load E = B " << " E = " << E) }
    void LDEC() {INST  E = C; PC++; cpum("Load E = C " << " E = " << E) }
    void LDED() {INST  E = D; PC++; cpum("Load E = D " << " E = " << E) }
    void LDEE() {INST  ; PC++; cpum("Load E = E " << " E = " << E) }
    void LDEH() {INST  E = H; PC++; cpum("Load E = H " << " E = " << E) }
    void LDEL() {INST  E = L; PC++; cpum("Load E = L " << " E = " << E) }

    void LDHA() {INST  H = A; PC++; cpum("Load H = A " << " H = " << H) }
    void LDHB() {INST  H = B; PC++; cpum("Load H = B " << " H = " << H) }
    void LDHC() {INST  H = C; PC++; cpum("Load H = C " << " H = " << H) }
    void LDHD() {INST  H = D; PC++; cpum("Load H = D " << " H = " << H) }
    void LDHE() {INST  H = E; PC++; cpum("Load H = E " << " H = " << H) }
    void LDHH() {INST  ; PC++; cpum("Load H = H " << " H = " << H) }
    void LDHL() {INST  H = L; PC++; cpum("Load H = L " << " H = " << H) }

    void LDLA() {INST  L = A; PC++; cpum("Load L = A " << " L = " << L) }
    void LDLB() {INST  L = B; PC++; cpum("Load L = B " << " L = " << L) }
    void LDLC() {INST  L = C; PC++; cpum("Load L = C " << " L = " << L) }
    void LDLD() {INST  L = D; PC++; cpum("Load L = D " << " L = " << L) }
    void LDLE() {INST  L = E; PC++; cpum("Load L = E " << " L = " << L) }
    void LDLH() {INST  L = H; PC++; cpum("Load L = H " << " L = " << L) }
    void LDLL() {INST  ; PC++; cpum("Load L = L " << " L = " << L) }

    void LDNA() {INST this->memory[*(uint16_t*)(this->memory + (PC + 1))] = A; PC += 3; }

    void LDMCA() {INST memory[0xff00 + C] = A; PC += 1; }

    void LDIAHL(){INST
        A = memory[(H << 8) + L];
        L++;
        if (!L) H++;
        cpum("Load & Inc A(" << std::hex << (int)A << ") = [HL = " << (H << 8) + L << "] ")
        PC++;
    }


    void loadBC() {INST
        B = memory[PC + 2];
        C = memory[PC + 1];
        cpum("Load " << std::hex << *(uint16_t*)(this->memory + (PC + 1)) << " into BC = "<< (int)B << " " << (int)C)
        PC += 3;
    }

    void loadDE() {INST
        D = memory[PC + 2];
        E = memory[PC + 1];
        cpum("Load " << std::hex << *(uint16_t*)(this->memory + (PC + 1)) << " into DE = "<< (int)D << " " << (int)E)
        PC += 3;
    }

    void loadHL() {INST
        H = memory[PC + 2];
        L = memory[PC + 1];
        cpum("Load " << std::hex << *(uint16_t*)(this->memory + (PC + 1)) << " into HL = "<< (int)H << " " << (int)L)
        PC += 3;
    }

    void loadSP() {INST
        this->SP = *(uint16_t*)(memory + PC + 1);
        cpum("Load " << std::hex << *(uint16_t*)(this->memory + (PC + 1)) << " into SP = "<< (int)SP)
        PC += 3;
    }

    void LDDHL() {INST
        memory[(H << 8) + L] = A;
        L--;
        if (L == 0xff)
        { H--; }
        cpum("Load & Dec [HL = " << (H << 8) + L << "] = A(" << std::hex << (int)memory[((H + 1) << 8) + L] << ")")
        PC++;
    }

    void LDIHL() {INST
        memory[(H << 8) + L] = A;
        cpum("Load & Inc [HL] = A -- HL[" << ((H << 8) + L) << "] = A(" << (int)A << ")" << (int)memory[(H << 8) + L]);
        L++;
        if (!L) H++;
        PC++;
    }

    void LDBCA() {INST
        memory[(B << 8) + C] = A;
        cpum("Load & Dec [BC = " << (B << 8) + C << "] = A(" << std::hex << (int)memory[((B + 1) << 8) + C] << ")")
        PC++;
    }

    void LDABC() {INST
        A = memory[(B << 8) + C];
        cpum("Load & Dec A (" << std::hex << (int)memory[((B + 1) << 8) + C] << ") = [BC = " << (B << 8) + C << "] ")
        PC++;
    }
/**/
    void LDDHNA() {INST
        memory[0xff00 + memory[PC + 1]] = A;
        cpum("Load [adr = " << 0xff00 + memory[PC + 1] << "] = A(" << std::hex << (int)A << ")")
        PC += 2;
    }

    void LDDHAN() {INST
        A = memory[0xff00 + memory[PC + 1]];
                   cpum("Load A(" << (int)A << ") = [adr = " << 0xff00 + memory[PC + 1] << "] = " << (int)memory[0xff00 + memory[PC + 1]])
        PC += 2;
    }
};

#endif // LOADS_H
