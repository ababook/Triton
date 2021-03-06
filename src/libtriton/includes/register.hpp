//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#ifndef TRITON_REGISTEROPERAND_H
#define TRITON_REGISTEROPERAND_H

#include <string>
#include <ostream>

#include "bitsVector.hpp"
#include "cpuSize.hpp"
#include "operandInterface.hpp"
#include "tritonTypes.hpp"



//! The Triton namespace
namespace triton {
/*!
 *  \addtogroup triton
 *  @{
 */

  //! The Triton namespace
  namespace arch {
  /*!
   *  \ingroup triton
   *  \addtogroup arch
   *  @{
   */

    /*! \class Register
     *  \brief This class is used when an instruction has a register operand.
     */
    class Register : public BitsVector, public OperandInterface {

      protected:
        //! The name of the register.
        std::string name;

        //! The id of the register.
        triton::uint32 id;

        //! The parent id of the register.
        triton::uint32 parent;

        //! The concrete value (content of the register)
        triton::uint512 concreteValue;

        //! True if this concrete register value is trusted and synchronized with the real CPU value.
        bool trusted;

        //! Copies a Register.
        void copy(const Register& other);

        //! Setup everything.
        void setup(triton::uint32 reg, triton::uint512 concreteValue);

        //! Resets information.
        void clear(void);

      public:
        //! Constructor.
        Register();

        //! Constructor.
        Register(triton::uint32 reg, triton::uint512 concreteValue=0);

        //! Constructor by copy.
        Register(const Register& other);

        //! Destructor.
        ~Register();

        //! Returns the parent id of the register.
        Register getParent(void) const;

        //! Returns true if the register is valid.
        bool isValid(void) const;

        //! Returns true if the register is a register.
        bool isRegister(void) const;

        //! Returns true if the register is a flag.
        bool isFlag(void) const;

        //! True if this concrete register value is trusted and synchronized with the real CPU value.
        bool isTrusted(void) const;

        //! Sets the trust flag.
        void setTrust(bool flag);

        //! Returns the name of the register.
        std::string getName(void) const;

        //! Returns the highest bit of the register vector. \sa BitsVector::getHigh()
        triton::uint32 getAbstractHigh(void) const;

        //! Returns the lower bit of the register vector. \sa BitsVector::getLow()
        triton::uint32 getAbstractLow(void) const;

        //! Returns the size (in bits) of the register.
        triton::uint32 getBitSize(void) const;

        //! Returns the id of the register.
        triton::uint32 getId(void) const;

        //! Returns the size (in bytes) of the register.
        triton::uint32 getSize(void) const;

        //! Returns the type of the operand (triton::arch::OP_REG).
        triton::uint32 getType(void) const;

        //! Returns the concrete value.
        triton::uint512 getConcreteValue(void) const;

        //! Copies a Register.
        void operator=(const Register& other);

        //! Sets the id of the register.
        void setId(triton::uint32 reg);

        //! Sets the parent id of the register.
        void setParent(triton::uint32 reg);

        //! Sets the concrete value of the register.
        void setConcreteValue(triton::uint512 concreteValue);
    };

    //! Displays a Register.
    std::ostream& operator<<(std::ostream& stream, const Register& reg);

    //! Displays a Register.
    std::ostream& operator<<(std::ostream& stream, const Register* reg);

    //! Compares two Register.
    bool operator==(const Register& reg1, const Register& reg2);

    //! Compares two Register.
    bool operator!=(const Register& reg1, const Register& reg2);

    //! Compares two Register (needed for std::map)
    bool operator<(const Register& reg1, const Register& reg2);

  /*! @} End of arch namespace */
  };
/*! @} End of triton namespace */
};

#endif /* TRITON_REGISTEROPERAND_H */
