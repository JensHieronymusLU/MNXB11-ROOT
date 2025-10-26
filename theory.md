## Please explain the difference in the two (#ifndef + #define and pragma once)

\#ifndef \_\_YOUR\_CLASS\_H\_\_

\#define \_\_YOUR\_CLASS\_H\_\_

\#endif // \_\_YOUR\_\CLASS\_H\_\_

checks is the macro is not defined and if it isnt defines it, meaning that multiple inclusions and therefore redefinition errors are avoided.

\#pragma once 

tells the compiler directly to only once include the file also avoiding the redefinition errors.
## What is the difference between struct and class?

Members of classes are private by default, and members of structs are public
## Why do we need our class to be derived from the TObject?

So we it can properly interact with .root files, such as trees (which we use). It also means that roots automatic memory management takes care of the object.

