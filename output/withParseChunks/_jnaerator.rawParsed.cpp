
extern ""C"" {
typedef int LLVMBool;
	/// The top-level container for all LLVM global data. See the LLVMContext class.
	typedef struct LLVMOpaqueContext *LLVMContextRef;
	/**
	 * The top-level container for all other LLVM Intermediate Representation (IR)<br>
	 * objects.<br>
	 * * @see llvm::Module
	 */
	typedef struct LLVMOpaqueModule *LLVMModuleRef;
	/**
	 * Each value in the LLVM IR has a type, an LLVMTypeRef.<br>
	 * * @see llvm::Type
	 */
	typedef struct LLVMOpaqueType *LLVMTypeRef;
	/**
	 * Represents an individual value in LLVM IR.<br>
	 * * This models llvm::Value.
	 */
	typedef struct LLVMOpaqueValue *LLVMValueRef;
	/**
	 * Represents a basic block of instructions in LLVM IR.<br>
	 * * This models llvm::BasicBlock.
	 */
	typedef struct LLVMOpaqueBasicBlock *LLVMBasicBlockRef;
	/**
	 * Represents an LLVM basic block builder.<br>
	 * * This models llvm::IRBuilder.
	 */
	typedef struct LLVMOpaqueBuilder *LLVMBuilderRef;
	/**
	 * Interface used to provide a module to JIT or interpreter.<br>
	 * This is now just a synonym for llvm::Module, but we have to keep using the<br>
	 * different type to keep binary compatibility.
	 */
	typedef struct LLVMOpaqueModuleProvider *LLVMModuleProviderRef;
	/**
	 * Used to provide a module to JIT or interpreter.<br>
	 * * @see llvm::MemoryBuffer
	 */
	typedef struct LLVMOpaqueMemoryBuffer *LLVMMemoryBufferRef;
	/// @see llvm::PassManagerBase
	typedef struct LLVMOpaquePassManager *LLVMPassManagerRef;
	/// @see llvm::PassRegistry
	typedef struct LLVMOpaquePassRegistry *LLVMPassRegistryRef;
	/**
	 * Used to get the users and usees of a Value.<br>
	 * * @see llvm::Use
	 */
	typedef struct LLVMOpaqueUse *LLVMUseRef;
	typedef enum {
		LLVMZExtAttribute = 1 << 0,
		LLVMSExtAttribute = 1 << 1,
		LLVMNoReturnAttribute = 1 << 2,
		LLVMInRegAttribute = 1 << 3,
		LLVMStructRetAttribute = 1 << 4,
		LLVMNoUnwindAttribute = 1 << 5,
		LLVMNoAliasAttribute = 1 << 6,
		LLVMByValAttribute = 1 << 7,
		LLVMNestAttribute = 1 << 8,
		LLVMReadNoneAttribute = 1 << 9,
		LLVMReadOnlyAttribute = 1 << 10,
		LLVMNoInlineAttribute = 1 << 11,
		LLVMAlwaysInlineAttribute = 1 << 12,
		LLVMOptimizeForSizeAttribute = 1 << 13,
		LLVMStackProtectAttribute = 1 << 14,
		LLVMStackProtectReqAttribute = 1 << 15,
		LLVMAlignment = 31 << 16,
		LLVMNoCaptureAttribute = 1 << 21,
		LLVMNoRedZoneAttribute = 1 << 22,
		LLVMNoImplicitFloatAttribute = 1 << 23,
		LLVMNakedAttribute = 1 << 24,
		LLVMInlineHintAttribute = 1 << 25,
		LLVMStackAlignment = 7 << 26,
		LLVMReturnsTwice = 1 << 29,
		LLVMUWTable = 1 << 30,
		LLVMNonLazyBind = 1 << 31
	} LLVMAttribute;
	typedef enum {
		/// Terminator Instructions
		LLVMRet = 1,
		LLVMBr = 2,
		LLVMSwitch = 3,
		LLVMIndirectBr = 4,
		LLVMInvoke = 5,
		/// removed 6 due to API changes
		LLVMUnreachable = 7,
		/// Standard Binary Operators
		LLVMAdd = 8,
		LLVMFAdd = 9,
		LLVMSub = 10,
		LLVMFSub = 11,
		LLVMMul = 12,
		LLVMFMul = 13,
		LLVMUDiv = 14,
		LLVMSDiv = 15,
		LLVMFDiv = 16,
		LLVMURem = 17,
		LLVMSRem = 18,
		LLVMFRem = 19,
		/// Logical Operators
		LLVMShl = 20,
		LLVMLShr = 21,
		LLVMAShr = 22,
		LLVMAnd = 23,
		LLVMOr = 24,
		LLVMXor = 25,
		/// Memory Operators
		LLVMAlloca = 26,
		LLVMLoad = 27,
		LLVMStore = 28,
		LLVMGetElementPtr = 29,
		/// Cast Operators
		LLVMTrunc = 30,
		LLVMZExt = 31,
		LLVMSExt = 32,
		LLVMFPToUI = 33,
		LLVMFPToSI = 34,
		LLVMUIToFP = 35,
		LLVMSIToFP = 36,
		LLVMFPTrunc = 37,
		LLVMFPExt = 38,
		LLVMPtrToInt = 39,
		LLVMIntToPtr = 40,
		LLVMBitCast = 41,
		/// Other Operators
		LLVMICmp = 42,
		LLVMFCmp = 43,
		LLVMPHI = 44,
		LLVMCall = 45,
		LLVMSelect = 46,
		LLVMUserOp1 = 47,
		LLVMUserOp2 = 48,
		LLVMVAArg = 49,
		LLVMExtractElement = 50,
		LLVMInsertElement = 51,
		LLVMShuffleVector = 52,
		LLVMExtractValue = 53,
		LLVMInsertValue = 54,
		/// Atomic operators
		LLVMFence = 55,
		LLVMAtomicCmpXchg = 56,
		LLVMAtomicRMW = 57,
		/// Exception Handling Operators
		LLVMResume = 58,
		LLVMLandingPad = 59
	} LLVMOpcode;
	typedef enum {
		LLVMVoidTypeKind /**< type with no size */,
		LLVMHalfTypeKind /**< 16 bit floating point type */,
		LLVMFloatTypeKind /**< 32 bit floating point type */,
		LLVMDoubleTypeKind /**< 64 bit floating point type */,
		LLVMX86_FP80TypeKind /**< 80 bit floating point type (X87) */,
		LLVMFP128TypeKind /**< 128 bit floating point type (112-bit mantissa)*/,
		LLVMPPC_FP128TypeKind /**< 128 bit floating point type (two 64-bits) */,
		LLVMLabelTypeKind /**< Labels */,
		LLVMIntegerTypeKind /**< Arbitrary bit width integers */,
		LLVMFunctionTypeKind /**< Functions */,
		LLVMStructTypeKind /**< Structures */,
		LLVMArrayTypeKind /**< Arrays */,
		LLVMPointerTypeKind /**< Pointers */,
		LLVMVectorTypeKind /**< SIMD 'packed' format, or other vector type */,
		LLVMMetadataTypeKind /**< Metadata */,
		LLVMX86_MMXTypeKind /**< X86 MMX */
	} LLVMTypeKind;
	typedef enum {
		LLVMExternalLinkage /**< Externally visible function */,
		LLVMAvailableExternallyLinkage,
		LLVMLinkOnceAnyLinkage /**< Keep one copy of function when linking (inline)*/,
		LLVMLinkOnceODRLinkage /**< Same, but only replaced by something
                            equivalent. */,
		LLVMLinkOnceODRAutoHideLinkage /**< Like LinkOnceODR, but possibly hidden. */,
		LLVMWeakAnyLinkage /**< Keep one copy of function when linking (weak) */,
		LLVMWeakODRLinkage /**< Same, but only replaced by something
                            equivalent. */,
		LLVMAppendingLinkage /**< Special purpose, only applies to global arrays */,
		LLVMInternalLinkage /**< Rename collisions when linking (static
                               functions) */,
		LLVMPrivateLinkage /**< Like Internal, but omit from symbol table */,
		LLVMDLLImportLinkage /**< Function to be imported from DLL */,
		LLVMDLLExportLinkage /**< Function to be accessible from DLL */,
		LLVMExternalWeakLinkage /**< ExternalWeak linkage description */,
		LLVMGhostLinkage /**< Obsolete */,
		LLVMCommonLinkage /**< Tentative definitions */,
		LLVMLinkerPrivateLinkage /**< Like Private, but linker removes. */,
		LLVMLinkerPrivateWeakLinkage /**< Like LinkerPrivate, but is weak. */
	} LLVMLinkage;
	typedef enum {
		LLVMDefaultVisibility /**< The GV is visible */,
		LLVMHiddenVisibility /**< The GV is hidden */,
		LLVMProtectedVisibility /**< The GV is protected */
	} LLVMVisibility;
	typedef enum {
		LLVMCCallConv = 0,
		LLVMFastCallConv = 8,
		LLVMColdCallConv = 9,
		LLVMX86StdcallCallConv = 64,
		LLVMX86FastcallCallConv = 65
	} LLVMCallConv;
	typedef enum {
		LLVMIntEQ = 32 /**< equal */,
		LLVMIntNE /**< not equal */,
		LLVMIntUGT /**< unsigned greater than */,
		LLVMIntUGE /**< unsigned greater or equal */,
		LLVMIntULT /**< unsigned less than */,
		LLVMIntULE /**< unsigned less or equal */,
		LLVMIntSGT /**< signed greater than */,
		LLVMIntSGE /**< signed greater or equal */,
		LLVMIntSLT /**< signed less than */,
		LLVMIntSLE /**< signed less or equal */
	} LLVMIntPredicate;
	typedef enum {
		LLVMRealPredicateFalse /**< Always false (always folded) */,
		LLVMRealOEQ /**< True if ordered and equal */,
		LLVMRealOGT /**< True if ordered and greater than */,
		LLVMRealOGE /**< True if ordered and greater than or equal */,
		LLVMRealOLT /**< True if ordered and less than */,
		LLVMRealOLE /**< True if ordered and less than or equal */,
		LLVMRealONE /**< True if ordered and operands are unequal */,
		LLVMRealORD /**< True if ordered (no nans) */,
		LLVMRealUNO /**< True if unordered: isnan(X) | isnan(Y) */,
		LLVMRealUEQ /**< True if unordered or equal */,
		LLVMRealUGT /**< True if unordered or greater than */,
		LLVMRealUGE /**< True if unordered, greater than, or equal */,
		LLVMRealULT /**< True if unordered or less than */,
		LLVMRealULE /**< True if unordered, less than, or equal */,
		LLVMRealUNE /**< True if unordered or not equal */,
		LLVMRealPredicateTrue /**< Always true (always folded) */
	} LLVMRealPredicate;
	typedef enum {
		LLVMLandingPadCatch /**< A catch clause   */,
		LLVMLandingPadFilter /**< A filter clause  */
	} LLVMLandingPadClauseTy;
	typedef enum {
		LLVMNotThreadLocal = 0,
		LLVMGeneralDynamicTLSModel,
		LLVMLocalDynamicTLSModel,
		LLVMInitialExecTLSModel,
		LLVMLocalExecTLSModel
	} LLVMThreadLocalMode;
	typedef enum {
		LLVMAtomicOrderingNotAtomic = 0 /**< A load or store which is not atomic */,
		LLVMAtomicOrderingUnordered = 1 /**< Lowest level of atomicity, guarantees
                                     somewhat sane results, lock free. */,
		LLVMAtomicOrderingMonotonic = 2 /**< guarantees that if you take all the 
                                     operations affecting a specific address, 
                                     a consistent ordering exists */,
		LLVMAtomicOrderingAcquire = 4 /**< Acquire provides a barrier of the sort 
                                   necessary to acquire a lock to access other 
                                   memory with normal loads and stores. */,
		LLVMAtomicOrderingRelease = 5 /**< Release is similar to Acquire, but with 
                                   a barrier of the sort necessary to release 
                                   a lock. */,
		LLVMAtomicOrderingAcquireRelease = 6 /**< provides both an Acquire and a 
                                          Release barrier (for fences and 
                                          operations which both read and write
                                           memory). */,
		LLVMAtomicOrderingSequentiallyConsistent = 7 /**< provides Acquire semantics 
                                                 for loads and Release 
                                                 semantics for stores. 
                                                 Additionally, it guarantees 
                                                 that a total ordering exists 
                                                 between all 
                                                 SequentiallyConsistent 
                                                 operations. */
	} LLVMAtomicOrdering;
	typedef enum {
		LLVMAtomicRMWBinOpXchg /**< Set the new value and return the one old */,
		LLVMAtomicRMWBinOpAdd /**< Add a value and return the old one */,
		LLVMAtomicRMWBinOpSub /**< Subtract a value and return the old one */,
		LLVMAtomicRMWBinOpAnd /**< And a value and return the old one */,
		LLVMAtomicRMWBinOpNand /**< Not-And a value and return the old one */,
		LLVMAtomicRMWBinOpOr /**< OR a value and return the old one */,
		LLVMAtomicRMWBinOpXor /**< Xor a value and return the old one */,
		LLVMAtomicRMWBinOpMax /**< Sets the value if it's greater than the
                             original using a signed comparison and return 
                             the old one */,
		LLVMAtomicRMWBinOpMin /**< Sets the value if it's Smaller than the
                             original using a signed comparison and return 
                             the old one */,
		LLVMAtomicRMWBinOpUMax /**< Sets the value if it's greater than the
                             original using an unsigned comparison and return 
                             the old one */,
		LLVMAtomicRMWBinOpUMin /**< Sets the value if it's greater than the
                             original using an unsigned comparison  and return 
                             the old one */
	} LLVMAtomicRMWBinOp;
	void LLVMInitializeCore(LLVMPassRegistryRef R);
	/**
	 * Deallocate and destroy all ManagedStatic variables.<br>
	 * @see llvm::llvm_shutdown<br>
	 * @see ManagedStatic
	 */
	void LLVMShutdown();
	void LLVMDisposeMessage(char* Message);
	/**
	 * Create a new context.<br>
	 * * Every call to this function should be paired with a call to<br>
	 * LLVMContextDispose() or the context will leak memory.
	 */
	LLVMContextRef LLVMContextCreate();
	/// Obtain the global context instance.
	LLVMContextRef LLVMGetGlobalContext();
	/**
	 * Destroy a context instance.<br>
	 * * This should be called for every call to LLVMContextCreate() or memory<br>
	 * will be leaked.
	 */
	void LLVMContextDispose(LLVMContextRef C);
	unsigned LLVMGetMDKindIDInContext(LLVMContextRef C, const char* Name, unsigned SLen);
	unsigned LLVMGetMDKindID(const char* Name, unsigned SLen);
	/**
	 * Create a new, empty module in the global context.<br>
	 * * This is equivalent to calling LLVMModuleCreateWithNameInContext with<br>
	 * LLVMGetGlobalContext() as the context parameter.<br>
	 * * Every invocation should be paired with LLVMDisposeModule() or memory<br>
	 * will be leaked.
	 */
	LLVMModuleRef LLVMModuleCreateWithName(const char* ModuleID);
	/**
	 * Create a new, empty module in a specific context.<br>
	 * * Every invocation should be paired with LLVMDisposeModule() or memory<br>
	 * will be leaked.
	 */
	LLVMModuleRef LLVMModuleCreateWithNameInContext(const char* ModuleID, LLVMContextRef C);
	/**
	 * Destroy a module instance.<br>
	 * * This must be called for every created module or memory will be<br>
	 * leaked.
	 */
	void LLVMDisposeModule(LLVMModuleRef M);
	/**
	 * Obtain the data layout for a module.<br>
	 * * @see Module::getDataLayout()
	 */
	const char* LLVMGetDataLayout(LLVMModuleRef M);
	/**
	 * Set the data layout for a module.<br>
	 * * @see Module::setDataLayout()
	 */
	void LLVMSetDataLayout(LLVMModuleRef M, const char* Triple);
	/**
	 * Obtain the target triple for a module.<br>
	 * * @see Module::getTargetTriple()
	 */
	const char* LLVMGetTarget(LLVMModuleRef M);
	/**
	 * Set the target triple for a module.<br>
	 * * @see Module::setTargetTriple()
	 */
	void LLVMSetTarget(LLVMModuleRef M, const char* Triple);
	/**
	 * Dump a representation of a module to stderr.<br>
	 * * @see Module::dump()
	 */
	void LLVMDumpModule(LLVMModuleRef M);
	/**
	 * Print a representation of a module to a file. The ErrorMessage needs to be<br>
	 * disposed with LLVMDisposeMessage. Returns 0 on success, 1 otherwise.<br>
	 * * @see Module::print()
	 */
	LLVMBool LLVMPrintModuleToFile(LLVMModuleRef M, const char* Filename, char** ErrorMessage);
	/**
	 * Set inline assembly for a module.<br>
	 * * @see Module::setModuleInlineAsm()
	 */
	void LLVMSetModuleInlineAsm(LLVMModuleRef M, const char* Asm);
	/**
	 * Obtain the context to which this module is associated.<br>
	 * * @see Module::getContext()
	 */
	LLVMContextRef LLVMGetModuleContext(LLVMModuleRef M);
	/// Obtain a Type from a module by its registered name.
	LLVMTypeRef LLVMGetTypeByName(LLVMModuleRef M, const char* Name);
	/**
	 * Obtain the number of operands for named metadata in a module.<br>
	 * * @see llvm::Module::getNamedMetadata()
	 */
	unsigned LLVMGetNamedMetadataNumOperands(LLVMModuleRef M, const char* name);
	/**
	 * Obtain the named metadata operands for a module.<br>
	 * * The passed LLVMValueRef pointer should refer to an array of<br>
	 * LLVMValueRef at least LLVMGetNamedMetadataNumOperands long. This<br>
	 * array will be populated with the LLVMValueRef instances. Each<br>
	 * instance corresponds to a llvm::MDNode.<br>
	 * * @see llvm::Module::getNamedMetadata()<br>
	 * @see llvm::MDNode::getOperand()
	 */
	void LLVMGetNamedMetadataOperands(LLVMModuleRef M, const char* name, LLVMValueRef* Dest);
	/**
	 * Add an operand to named metadata.<br>
	 * * @see llvm::Module::getNamedMetadata()<br>
	 * @see llvm::MDNode::addOperand()
	 */
	void LLVMAddNamedMetadataOperand(LLVMModuleRef M, const char* name, LLVMValueRef Val);
	/**
	 * Add a function to a module under a specified name.<br>
	 * * @see llvm::Function::Create()
	 */
	LLVMValueRef LLVMAddFunction(LLVMModuleRef M, const char* Name, LLVMTypeRef FunctionTy);
	/**
	 * Obtain a Function value from a Module by its name.<br>
	 * * The returned value corresponds to a llvm::Function value.<br>
	 * * @see llvm::Module::getFunction()
	 */
	LLVMValueRef LLVMGetNamedFunction(LLVMModuleRef M, const char* Name);
	/**
	 * Obtain an iterator to the first Function in a Module.<br>
	 * * @see llvm::Module::begin()
	 */
	LLVMValueRef LLVMGetFirstFunction(LLVMModuleRef M);
	/**
	 * Obtain an iterator to the last Function in a Module.<br>
	 * * @see llvm::Module::end()
	 */
	LLVMValueRef LLVMGetLastFunction(LLVMModuleRef M);
	/**
	 * Advance a Function iterator to the next Function.<br>
	 * * Returns NULL if the iterator was already at the end and there are no more<br>
	 * functions.
	 */
	LLVMValueRef LLVMGetNextFunction(LLVMValueRef Fn);
	/**
	 * Decrement a Function iterator to the previous Function.<br>
	 * * Returns NULL if the iterator was already at the beginning and there are<br>
	 * no previous functions.
	 */
	LLVMValueRef LLVMGetPreviousFunction(LLVMValueRef Fn);
	/**
	 * Obtain the enumerated type of a Type instance.<br>
	 * * @see llvm::Type:getTypeID()
	 */
	LLVMTypeKind LLVMGetTypeKind(LLVMTypeRef Ty);
	/**
	 * Whether the type has a known size.<br>
	 * * Things that don't have a size are abstract types, labels, and void.a<br>
	 * * @see llvm::Type::isSized()
	 */
	LLVMBool LLVMTypeIsSized(LLVMTypeRef Ty);
	/**
	 * Obtain the context to which this type instance is associated.<br>
	 * * @see llvm::Type::getContext()
	 */
	LLVMContextRef LLVMGetTypeContext(LLVMTypeRef Ty);
	/// Obtain an integer type from a context with specified bit width.
	LLVMTypeRef LLVMInt1TypeInContext(LLVMContextRef C);
	LLVMTypeRef LLVMInt8TypeInContext(LLVMContextRef C);
	LLVMTypeRef LLVMInt16TypeInContext(LLVMContextRef C);
	LLVMTypeRef LLVMInt32TypeInContext(LLVMContextRef C);
	LLVMTypeRef LLVMInt64TypeInContext(LLVMContextRef C);
	LLVMTypeRef LLVMIntTypeInContext(LLVMContextRef C, unsigned NumBits);
	/**
	 * Obtain an integer type from the global context with a specified bit<br>
	 * width.
	 */
	LLVMTypeRef LLVMInt1Type();
	LLVMTypeRef LLVMInt8Type();
	LLVMTypeRef LLVMInt16Type();
	LLVMTypeRef LLVMInt32Type();
	LLVMTypeRef LLVMInt64Type();
	LLVMTypeRef LLVMIntType(unsigned NumBits);
	unsigned LLVMGetIntTypeWidth(LLVMTypeRef IntegerTy);
	/// Obtain a 16-bit floating point type from a context.
	LLVMTypeRef LLVMHalfTypeInContext(LLVMContextRef C);
	/// Obtain a 32-bit floating point type from a context.
	LLVMTypeRef LLVMFloatTypeInContext(LLVMContextRef C);
	/// Obtain a 64-bit floating point type from a context.
	LLVMTypeRef LLVMDoubleTypeInContext(LLVMContextRef C);
	/// Obtain a 80-bit floating point type (X87) from a context.
	LLVMTypeRef LLVMX86FP80TypeInContext(LLVMContextRef C);
	/**
	 * Obtain a 128-bit floating point type (112-bit mantissa) from a<br>
	 * context.
	 */
	LLVMTypeRef LLVMFP128TypeInContext(LLVMContextRef C);
	/// Obtain a 128-bit floating point type (two 64-bits) from a context.
	LLVMTypeRef LLVMPPCFP128TypeInContext(LLVMContextRef C);
	/**
	 * Obtain a floating point type from the global context.<br>
	 * * These map to the functions in this group of the same name.
	 */
	LLVMTypeRef LLVMHalfType();
	LLVMTypeRef LLVMFloatType();
	LLVMTypeRef LLVMDoubleType();
	LLVMTypeRef LLVMX86FP80Type();
	LLVMTypeRef LLVMFP128Type();
	LLVMTypeRef LLVMPPCFP128Type();
	/**
	 * Obtain a function type consisting of a specified signature.<br>
	 * * The function is defined as a tuple of a return Type, a list of<br>
	 * parameter types, and whether the function is variadic.
	 */
	LLVMTypeRef LLVMFunctionType(LLVMTypeRef ReturnType, LLVMTypeRef* ParamTypes, unsigned ParamCount, LLVMBool IsVarArg);
	/// Returns whether a function type is variadic.
	LLVMBool LLVMIsFunctionVarArg(LLVMTypeRef FunctionTy);
	/// Obtain the Type this function Type returns.
	LLVMTypeRef LLVMGetReturnType(LLVMTypeRef FunctionTy);
	/// Obtain the number of parameters this function accepts.
	unsigned LLVMCountParamTypes(LLVMTypeRef FunctionTy);
	/**
	 * Obtain the types of a function's parameters.<br>
	 * * The Dest parameter should point to a pre-allocated array of<br>
	 * LLVMTypeRef at least LLVMCountParamTypes() large. On return, the<br>
	 * first LLVMCountParamTypes() entries in the array will be populated<br>
	 * with LLVMTypeRef instances.<br>
	 * * @param FunctionTy The function type to operate on.<br>
	 * @param Dest Memory address of an array to be filled with result.
	 */
	void LLVMGetParamTypes(LLVMTypeRef FunctionTy, LLVMTypeRef* Dest);
	/**
	 * Create a new structure type in a context.<br>
	 * * A structure is specified by a list of inner elements/types and<br>
	 * whether these can be packed together.<br>
	 * * @see llvm::StructType::create()
	 */
	LLVMTypeRef LLVMStructTypeInContext(LLVMContextRef C, LLVMTypeRef* ElementTypes, unsigned ElementCount, LLVMBool Packed);
	/**
	 * Create a new structure type in the global context.<br>
	 * * @see llvm::StructType::create()
	 */
	LLVMTypeRef LLVMStructType(LLVMTypeRef* ElementTypes, unsigned ElementCount, LLVMBool Packed);
	/**
	 * Create an empty structure in a context having a specified name.<br>
	 * * @see llvm::StructType::create()
	 */
	LLVMTypeRef LLVMStructCreateNamed(LLVMContextRef C, const char* Name);
	/**
	 * Obtain the name of a structure.<br>
	 * * @see llvm::StructType::getName()
	 */
	const char* LLVMGetStructName(LLVMTypeRef Ty);
	/**
	 * Set the contents of a structure type.<br>
	 * * @see llvm::StructType::setBody()
	 */
	void LLVMStructSetBody(LLVMTypeRef StructTy, LLVMTypeRef* ElementTypes, unsigned ElementCount, LLVMBool Packed);
	/**
	 * Get the number of elements defined inside the structure.<br>
	 * * @see llvm::StructType::getNumElements()
	 */
	unsigned LLVMCountStructElementTypes(LLVMTypeRef StructTy);
	/**
	 * Get the elements within a structure.<br>
	 * * The function is passed the address of a pre-allocated array of<br>
	 * LLVMTypeRef at least LLVMCountStructElementTypes() long. After<br>
	 * invocation, this array will be populated with the structure's<br>
	 * elements. The objects in the destination array will have a lifetime<br>
	 * of the structure type itself, which is the lifetime of the context it<br>
	 * is contained in.
	 */
	void LLVMGetStructElementTypes(LLVMTypeRef StructTy, LLVMTypeRef* Dest);
	/**
	 * Determine whether a structure is packed.<br>
	 * * @see llvm::StructType::isPacked()
	 */
	LLVMBool LLVMIsPackedStruct(LLVMTypeRef StructTy);
	/**
	 * Determine whether a structure is opaque.<br>
	 * * @see llvm::StructType::isOpaque()
	 */
	LLVMBool LLVMIsOpaqueStruct(LLVMTypeRef StructTy);
	/**
	 * Obtain the type of elements within a sequential type.<br>
	 * * This works on array, vector, and pointer types.<br>
	 * * @see llvm::SequentialType::getElementType()
	 */
	LLVMTypeRef LLVMGetElementType(LLVMTypeRef Ty);
	/**
	 * Create a fixed size array type that refers to a specific type.<br>
	 * * The created type will exist in the context that its element type<br>
	 * exists in.<br>
	 * * @see llvm::ArrayType::get()
	 */
	LLVMTypeRef LLVMArrayType(LLVMTypeRef ElementType, unsigned ElementCount);
	/**
	 * Obtain the length of an array type.<br>
	 * * This only works on types that represent arrays.<br>
	 * * @see llvm::ArrayType::getNumElements()
	 */
	unsigned LLVMGetArrayLength(LLVMTypeRef ArrayTy);
	/**
	 * Create a pointer type that points to a defined type.<br>
	 * * The created type will exist in the context that its pointee type<br>
	 * exists in.<br>
	 * * @see llvm::PointerType::get()
	 */
	LLVMTypeRef LLVMPointerType(LLVMTypeRef ElementType, unsigned AddressSpace);
	/**
	 * Obtain the address space of a pointer type.<br>
	 * * This only works on types that represent pointers.<br>
	 * * @see llvm::PointerType::getAddressSpace()
	 */
	unsigned LLVMGetPointerAddressSpace(LLVMTypeRef PointerTy);
	/**
	 * Create a vector type that contains a defined type and has a specific<br>
	 * number of elements.<br>
	 * * The created type will exist in the context thats its element type<br>
	 * exists in.<br>
	 * * @see llvm::VectorType::get()
	 */
	LLVMTypeRef LLVMVectorType(LLVMTypeRef ElementType, unsigned ElementCount);
	/**
	 * Obtain the number of elements in a vector type.<br>
	 * * This only works on types that represent vectors.<br>
	 * * @see llvm::VectorType::getNumElements()
	 */
	unsigned LLVMGetVectorSize(LLVMTypeRef VectorTy);
	/// Create a void type in a context.
	LLVMTypeRef LLVMVoidTypeInContext(LLVMContextRef C);
	/// Create a label type in a context.
	LLVMTypeRef LLVMLabelTypeInContext(LLVMContextRef C);
	/// Create a X86 MMX type in a context.
	LLVMTypeRef LLVMX86MMXTypeInContext(LLVMContextRef C);
	/**
	 * These are similar to the above functions except they operate on the<br>
	 * global context.
	 */
	LLVMTypeRef LLVMVoidType();
	LLVMTypeRef LLVMLabelType();
	LLVMTypeRef LLVMX86MMXType();
	/**
	 * Obtain the type of a value.<br>
	 * * @see llvm::Value::getType()
	 */
	LLVMTypeRef LLVMTypeOf(LLVMValueRef Val);
	/**
	 * Obtain the string name of a value.<br>
	 * * @see llvm::Value::getName()
	 */
	const char* LLVMGetValueName(LLVMValueRef Val);
	/**
	 * Set the string name of a value.<br>
	 * * @see llvm::Value::setName()
	 */
	void LLVMSetValueName(LLVMValueRef Val, const char* Name);
	/**
	 * Dump a representation of a value to stderr.<br>
	 * * @see llvm::Value::dump()
	 */
	void LLVMDumpValue(LLVMValueRef Val);
	/**
	 * Replace all uses of a value with another one.<br>
	 * * @see llvm::Value::replaceAllUsesWith()
	 */
	void LLVMReplaceAllUsesWith(LLVMValueRef OldVal, LLVMValueRef NewVal);
	/// Determine whether the specified constant instance is constant.
	LLVMBool LLVMIsConstant(LLVMValueRef Val);
	/// Determine whether a value instance is undefined.
	LLVMBool LLVMIsUndef(LLVMValueRef Val);
	LLVMValueRef LLVMIsAArgument(LLVMValueRef Val);
	LLVMValueRef LLVMIsABasicBlock(LLVMValueRef Val);
	LLVMValueRef LLVMIsAInlineAsm(LLVMValueRef Val);
	LLVMValueRef LLVMIsAMDNode(LLVMValueRef Val);
	LLVMValueRef LLVMIsAMDString(LLVMValueRef Val);
	LLVMValueRef LLVMIsAUser(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstant(LLVMValueRef Val);
	LLVMValueRef LLVMIsABlockAddress(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstantAggregateZero(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstantArray(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstantExpr(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstantFP(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstantInt(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstantPointerNull(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstantStruct(LLVMValueRef Val);
	LLVMValueRef LLVMIsAConstantVector(LLVMValueRef Val);
	LLVMValueRef LLVMIsAGlobalValue(LLVMValueRef Val);
	LLVMValueRef LLVMIsAFunction(LLVMValueRef Val);
	LLVMValueRef LLVMIsAGlobalAlias(LLVMValueRef Val);
	LLVMValueRef LLVMIsAGlobalVariable(LLVMValueRef Val);
	LLVMValueRef LLVMIsAUndefValue(LLVMValueRef Val);
	LLVMValueRef LLVMIsAInstruction(LLVMValueRef Val);
	LLVMValueRef LLVMIsABinaryOperator(LLVMValueRef Val);
	LLVMValueRef LLVMIsACallInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAIntrinsicInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsADbgInfoIntrinsic(LLVMValueRef Val);
	LLVMValueRef LLVMIsADbgDeclareInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAMemIntrinsic(LLVMValueRef Val);
	LLVMValueRef LLVMIsAMemCpyInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAMemMoveInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAMemSetInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsACmpInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAFCmpInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAICmpInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAExtractElementInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAGetElementPtrInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAInsertElementInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAInsertValueInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsALandingPadInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAPHINode(LLVMValueRef Val);
	LLVMValueRef LLVMIsASelectInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAShuffleVectorInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAStoreInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsATerminatorInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsABranchInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAIndirectBrInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAInvokeInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAReturnInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsASwitchInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAUnreachableInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAResumeInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAUnaryInstruction(LLVMValueRef Val);
	LLVMValueRef LLVMIsAAllocaInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsACastInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsABitCastInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAFPExtInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAFPToSIInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAFPToUIInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAFPTruncInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAIntToPtrInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAPtrToIntInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsASExtInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsASIToFPInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsATruncInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAUIToFPInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAZExtInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAExtractValueInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsALoadInst(LLVMValueRef Val);
	LLVMValueRef LLVMIsAVAArgInst(LLVMValueRef Val);
	/**
	 * Obtain the first use of a value.<br>
	 * * Uses are obtained in an iterator fashion. First, call this function<br>
	 * to obtain a reference to the first use. Then, call LLVMGetNextUse()<br>
	 * on that instance and all subsequently obtained instances until<br>
	 * LLVMGetNextUse() returns NULL.<br>
	 * * @see llvm::Value::use_begin()
	 */
	LLVMUseRef LLVMGetFirstUse(LLVMValueRef Val);
	/**
	 * Obtain the next use of a value.<br>
	 * * This effectively advances the iterator. It returns NULL if you are on<br>
	 * the final use and no more are available.
	 */
	LLVMUseRef LLVMGetNextUse(LLVMUseRef U);
	/**
	 * Obtain the user value for a user.<br>
	 * * The returned value corresponds to a llvm::User type.<br>
	 * * @see llvm::Use::getUser()
	 */
	LLVMValueRef LLVMGetUser(LLVMUseRef U);
	/**
	 * Obtain the value this use corresponds to.<br>
	 * * @see llvm::Use::get().
	 */
	LLVMValueRef LLVMGetUsedValue(LLVMUseRef U);
	/**
	 * Obtain an operand at a specific index in a llvm::User value.<br>
	 * * @see llvm::User::getOperand()
	 */
	LLVMValueRef LLVMGetOperand(LLVMValueRef Val, unsigned Index);
	/**
	 * Set an operand at a specific index in a llvm::User value.<br>
	 * * @see llvm::User::setOperand()
	 */
	void LLVMSetOperand(LLVMValueRef User, unsigned Index, LLVMValueRef Val);
	/**
	 * Obtain the number of operands in a llvm::User value.<br>
	 * * @see llvm::User::getNumOperands()
	 */
	int LLVMGetNumOperands(LLVMValueRef Val);
	/**
	 * Obtain a constant value referring to the null instance of a type.<br>
	 * * @see llvm::Constant::getNullValue()
	 */
	LLVMValueRef LLVMConstNull(LLVMTypeRef Ty); /* all zeroes */
	/**
	 * Obtain a constant value referring to the instance of a type<br>
	 * consisting of all ones.<br>
	 * * This is only valid for integer types.<br>
	 * * @see llvm::Constant::getAllOnesValue()
	 */
	LLVMValueRef LLVMConstAllOnes(LLVMTypeRef Ty);
	/**
	 * Obtain a constant value referring to an undefined value of a type.<br>
	 * * @see llvm::UndefValue::get()
	 */
	LLVMValueRef LLVMGetUndef(LLVMTypeRef Ty);
	/**
	 * Determine whether a value instance is null.<br>
	 * * @see llvm::Constant::isNullValue()
	 */
	LLVMBool LLVMIsNull(LLVMValueRef Val);
	/**
	 * Obtain a constant that is a constant pointer pointing to NULL for a<br>
	 * specified type.
	 */
	LLVMValueRef LLVMConstPointerNull(LLVMTypeRef Ty);
	/**
	 * Obtain a constant value for an integer type.<br>
	 * * The returned value corresponds to a llvm::ConstantInt.<br>
	 * * @see llvm::ConstantInt::get()<br>
	 * * @param IntTy Integer type to obtain value of.<br>
	 * @param N The value the returned instance should refer to.<br>
	 * @param SignExtend Whether to sign extend the produced value.
	 */
	LLVMValueRef LLVMConstInt(LLVMTypeRef IntTy, unsigned long long N, LLVMBool SignExtend);
	/**
	 * Obtain a constant value for an integer of arbitrary precision.<br>
	 * * @see llvm::ConstantInt::get()
	 */
	LLVMValueRef LLVMConstIntOfArbitraryPrecision(LLVMTypeRef IntTy, unsigned NumWords, const uint64_t Words);
	/**
	 * Obtain a constant value for an integer parsed from a string.<br>
	 * * A similar API, LLVMConstIntOfStringAndSize is also available. If the<br>
	 * string's length is available, it is preferred to call that function<br>
	 * instead.<br>
	 * * @see llvm::ConstantInt::get()
	 */
	LLVMValueRef LLVMConstIntOfString(LLVMTypeRef IntTy, const char* Text, uint8_t Radix);
	/**
	 * Obtain a constant value for an integer parsed from a string with<br>
	 * specified length.<br>
	 * * @see llvm::ConstantInt::get()
	 */
	LLVMValueRef LLVMConstIntOfStringAndSize(LLVMTypeRef IntTy, const char* Text, unsigned SLen, uint8_t Radix);
	/// Obtain a constant value referring to a double floating point value.
	LLVMValueRef LLVMConstReal(LLVMTypeRef RealTy, double N);
	/**
	 * Obtain a constant for a floating point value parsed from a string.<br>
	 * * A similar API, LLVMConstRealOfStringAndSize is also available. It<br>
	 * should be used if the input string's length is known.
	 */
	LLVMValueRef LLVMConstRealOfString(LLVMTypeRef RealTy, const char* Text);
	/// Obtain a constant for a floating point value parsed from a string.
	LLVMValueRef LLVMConstRealOfStringAndSize(LLVMTypeRef RealTy, const char* Text, unsigned SLen);
	/**
	 * Obtain the zero extended value for an integer constant value.<br>
	 * * @see llvm::ConstantInt::getZExtValue()
	 */
	unsigned long long LLVMConstIntGetZExtValue(LLVMValueRef ConstantVal);
	/**
	 * Obtain the sign extended value for an integer constant value.<br>
	 * * @see llvm::ConstantInt::getSExtValue()
	 */
	long long LLVMConstIntGetSExtValue(LLVMValueRef ConstantVal);
	/**
	 * Create a ConstantDataSequential and initialize it with a string.<br>
	 * * @see llvm::ConstantDataArray::getString()
	 */
	LLVMValueRef LLVMConstStringInContext(LLVMContextRef C, const char* Str, unsigned Length, LLVMBool DontNullTerminate);
	/**
	 * Create a ConstantDataSequential with string content in the global context.<br>
	 * * This is the same as LLVMConstStringInContext except it operates on the<br>
	 * global context.<br>
	 * * @see LLVMConstStringInContext()<br>
	 * @see llvm::ConstantDataArray::getString()
	 */
	LLVMValueRef LLVMConstString(const char* Str, unsigned Length, LLVMBool DontNullTerminate);
	/**
	 * Create an anonymous ConstantStruct with the specified values.<br>
	 * * @see llvm::ConstantStruct::getAnon()
	 */
	LLVMValueRef LLVMConstStructInContext(LLVMContextRef C, LLVMValueRef* ConstantVals, unsigned Count, LLVMBool Packed);
	/**
	 * Create a ConstantStruct in the global Context.<br>
	 * * This is the same as LLVMConstStructInContext except it operates on the<br>
	 * global Context.<br>
	 * * @see LLVMConstStructInContext()
	 */
	LLVMValueRef LLVMConstStruct(LLVMValueRef* ConstantVals, unsigned Count, LLVMBool Packed);
	/**
	 * Create a ConstantArray from values.<br>
	 * * @see llvm::ConstantArray::get()
	 */
	LLVMValueRef LLVMConstArray(LLVMTypeRef ElementTy, LLVMValueRef* ConstantVals, unsigned Length);
	/**
	 * Create a non-anonymous ConstantStruct from values.<br>
	 * * @see llvm::ConstantStruct::get()
	 */
	LLVMValueRef LLVMConstNamedStruct(LLVMTypeRef StructTy, LLVMValueRef* ConstantVals, unsigned Count);
	/**
	 * Create a ConstantVector from values.<br>
	 * * @see llvm::ConstantVector::get()
	 */
	LLVMValueRef LLVMConstVector(LLVMValueRef* ScalarConstantVals, unsigned Size);
	/**
	 * @defgroup LLVMCCoreValueConstantExpressions Constant Expressions<br>
	 * * Functions in this group correspond to APIs on llvm::ConstantExpr.<br>
	 * * @see llvm::ConstantExpr.<br>
	 * * @{
	 */
	LLVMOpcode LLVMGetConstOpcode(LLVMValueRef ConstantVal);
	LLVMValueRef LLVMAlignOf(LLVMTypeRef Ty);
	LLVMValueRef LLVMSizeOf(LLVMTypeRef Ty);
	LLVMValueRef LLVMConstNeg(LLVMValueRef ConstantVal);
	LLVMValueRef LLVMConstNSWNeg(LLVMValueRef ConstantVal);
	LLVMValueRef LLVMConstNUWNeg(LLVMValueRef ConstantVal);
	LLVMValueRef LLVMConstFNeg(LLVMValueRef ConstantVal);
	LLVMValueRef LLVMConstNot(LLVMValueRef ConstantVal);
	LLVMValueRef LLVMConstAdd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstNSWAdd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstNUWAdd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstFAdd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstSub(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstNSWSub(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstNUWSub(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstFSub(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstMul(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstNSWMul(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstNUWMul(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstFMul(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstUDiv(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstSDiv(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstExactSDiv(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstFDiv(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstURem(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstSRem(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstFRem(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstAnd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstOr(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstXor(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstICmp(LLVMIntPredicate Predicate, LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstFCmp(LLVMRealPredicate Predicate, LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstShl(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstLShr(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstAShr(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	LLVMValueRef LLVMConstGEP(LLVMValueRef ConstantVal, LLVMValueRef* ConstantIndices, unsigned NumIndices);
	LLVMValueRef LLVMConstInBoundsGEP(LLVMValueRef ConstantVal, LLVMValueRef* ConstantIndices, unsigned NumIndices);
	LLVMValueRef LLVMConstTrunc(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstSExt(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstZExt(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstFPTrunc(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstFPExt(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstUIToFP(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstSIToFP(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstFPToUI(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstFPToSI(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstPtrToInt(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstIntToPtr(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstBitCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstZExtOrBitCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstSExtOrBitCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstTruncOrBitCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstPointerCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstIntCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType, LLVMBool isSigned);
	LLVMValueRef LLVMConstFPCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	LLVMValueRef LLVMConstSelect(LLVMValueRef ConstantCondition, LLVMValueRef ConstantIfTrue, LLVMValueRef ConstantIfFalse);
	LLVMValueRef LLVMConstExtractElement(LLVMValueRef VectorConstant, LLVMValueRef IndexConstant);
	LLVMValueRef LLVMConstInsertElement(LLVMValueRef VectorConstant, LLVMValueRef ElementValueConstant, LLVMValueRef IndexConstant);
	LLVMValueRef LLVMConstShuffleVector(LLVMValueRef VectorAConstant, LLVMValueRef VectorBConstant, LLVMValueRef MaskConstant);
	LLVMValueRef LLVMConstExtractValue(LLVMValueRef AggConstant, unsigned* IdxList, unsigned NumIdx);
	LLVMValueRef LLVMConstInsertValue(LLVMValueRef AggConstant, LLVMValueRef ElementValueConstant, unsigned* IdxList, unsigned NumIdx);
	LLVMValueRef LLVMConstInlineAsm(LLVMTypeRef Ty, const char* AsmString, const char* Constraints, LLVMBool HasSideEffects, LLVMBool IsAlignStack);
	LLVMValueRef LLVMBlockAddress(LLVMValueRef F, LLVMBasicBlockRef BB);
	LLVMModuleRef LLVMGetGlobalParent(LLVMValueRef Global);
	LLVMBool LLVMIsDeclaration(LLVMValueRef Global);
	LLVMLinkage LLVMGetLinkage(LLVMValueRef Global);
	void LLVMSetLinkage(LLVMValueRef Global, LLVMLinkage Linkage);
	const char* LLVMGetSection(LLVMValueRef Global);
	void LLVMSetSection(LLVMValueRef Global, const char* Section);
	LLVMVisibility LLVMGetVisibility(LLVMValueRef Global);
	void LLVMSetVisibility(LLVMValueRef Global, LLVMVisibility Viz);
	unsigned LLVMGetAlignment(LLVMValueRef Global);
	void LLVMSetAlignment(LLVMValueRef Global, unsigned Bytes);
	/**
	 * @defgroup LLVMCoreValueConstantGlobalVariable Global Variables<br>
	 * * This group contains functions that operate on global variable values.<br>
	 * * @see llvm::GlobalVariable<br>
	 * * @{
	 */
	LLVMValueRef LLVMAddGlobal(LLVMModuleRef M, LLVMTypeRef Ty, const char* Name);
	LLVMValueRef LLVMAddGlobalInAddressSpace(LLVMModuleRef M, LLVMTypeRef Ty, const char* Name, unsigned AddressSpace);
	LLVMValueRef LLVMGetNamedGlobal(LLVMModuleRef M, const char* Name);
	LLVMValueRef LLVMGetFirstGlobal(LLVMModuleRef M);
	LLVMValueRef LLVMGetLastGlobal(LLVMModuleRef M);
	LLVMValueRef LLVMGetNextGlobal(LLVMValueRef GlobalVar);
	LLVMValueRef LLVMGetPreviousGlobal(LLVMValueRef GlobalVar);
	void LLVMDeleteGlobal(LLVMValueRef GlobalVar);
	LLVMValueRef LLVMGetInitializer(LLVMValueRef GlobalVar);
	void LLVMSetInitializer(LLVMValueRef GlobalVar, LLVMValueRef ConstantVal);
	LLVMBool LLVMIsThreadLocal(LLVMValueRef GlobalVar);
	void LLVMSetThreadLocal(LLVMValueRef GlobalVar, LLVMBool IsThreadLocal);
	LLVMBool LLVMIsGlobalConstant(LLVMValueRef GlobalVar);
	void LLVMSetGlobalConstant(LLVMValueRef GlobalVar, LLVMBool IsConstant);
	LLVMThreadLocalMode LLVMGetThreadLocalMode(LLVMValueRef GlobalVar);
	void LLVMSetThreadLocalMode(LLVMValueRef GlobalVar, LLVMThreadLocalMode Mode);
	LLVMBool LLVMIsExternallyInitialized(LLVMValueRef GlobalVar);
	void LLVMSetExternallyInitialized(LLVMValueRef GlobalVar, LLVMBool IsExtInit);
	/**
	 * @defgroup LLVMCoreValueConstantGlobalAlias Global Aliases<br>
	 * * This group contains function that operate on global alias values.<br>
	 * * @see llvm::GlobalAlias<br>
	 * * @{
	 */
	LLVMValueRef LLVMAddAlias(LLVMModuleRef M, LLVMTypeRef Ty, LLVMValueRef Aliasee, const char* Name);
	/**
	 * Remove a function from its containing module and deletes it.<br>
	 * * @see llvm::Function::eraseFromParent()
	 */
	void LLVMDeleteFunction(LLVMValueRef Fn);
	/**
	 * Obtain the ID number from a function instance.<br>
	 * * @see llvm::Function::getIntrinsicID()
	 */
	unsigned LLVMGetIntrinsicID(LLVMValueRef Fn);
	/**
	 * Obtain the calling function of a function.<br>
	 * * The returned value corresponds to the LLVMCallConv enumeration.<br>
	 * * @see llvm::Function::getCallingConv()
	 */
	unsigned LLVMGetFunctionCallConv(LLVMValueRef Fn);
	/**
	 * Set the calling convention of a function.<br>
	 * * @see llvm::Function::setCallingConv()<br>
	 * * @param Fn Function to operate on<br>
	 * @param CC LLVMCallConv to set calling convention to
	 */
	void LLVMSetFunctionCallConv(LLVMValueRef Fn, unsigned CC);
	/**
	 * Obtain the name of the garbage collector to use during code<br>
	 * generation.<br>
	 * * @see llvm::Function::getGC()
	 */
	const char* LLVMGetGC(LLVMValueRef Fn);
	/**
	 * Define the garbage collector to use during code generation.<br>
	 * * @see llvm::Function::setGC()
	 */
	void LLVMSetGC(LLVMValueRef Fn, const char* Name);
	/**
	 * Add an attribute to a function.<br>
	 * * @see llvm::Function::addAttribute()
	 */
	void LLVMAddFunctionAttr(LLVMValueRef Fn, LLVMAttribute PA);
	/**
	 * Add a target-dependent attribute to a fuction<br>
	 * @see llvm::AttrBuilder::addAttribute()
	 */
	void LLVMAddTargetDependentFunctionAttr(LLVMValueRef Fn, const char* A, const char* V);
	/**
	 * Obtain an attribute from a function.<br>
	 * * @see llvm::Function::getAttributes()
	 */
	LLVMAttribute LLVMGetFunctionAttr(LLVMValueRef Fn);
	/// Remove an attribute from a function.
	void LLVMRemoveFunctionAttr(LLVMValueRef Fn, LLVMAttribute PA);
	/**
	 * Obtain the number of parameters in a function.<br>
	 * * @see llvm::Function::arg_size()
	 */
	unsigned LLVMCountParams(LLVMValueRef Fn);
	/**
	 * Obtain the parameters in a function.<br>
	 * * The takes a pointer to a pre-allocated array of LLVMValueRef that is<br>
	 * at least LLVMCountParams() long. This array will be filled with<br>
	 * LLVMValueRef instances which correspond to the parameters the<br>
	 * function receives. Each LLVMValueRef corresponds to a llvm::Argument<br>
	 * instance.<br>
	 * * @see llvm::Function::arg_begin()
	 */
	void LLVMGetParams(LLVMValueRef Fn, LLVMValueRef* Params);
	/**
	 * Obtain the parameter at the specified index.<br>
	 * * Parameters are indexed from 0.<br>
	 * * @see llvm::Function::arg_begin()
	 */
	LLVMValueRef LLVMGetParam(LLVMValueRef Fn, unsigned Index);
	/**
	 * Obtain the function to which this argument belongs.<br>
	 * * Unlike other functions in this group, this one takes a LLVMValueRef<br>
	 * that corresponds to a llvm::Attribute.<br>
	 * * The returned LLVMValueRef is the llvm::Function to which this<br>
	 * argument belongs.
	 */
	LLVMValueRef LLVMGetParamParent(LLVMValueRef Inst);
	/**
	 * Obtain the first parameter to a function.<br>
	 * * @see llvm::Function::arg_begin()
	 */
	LLVMValueRef LLVMGetFirstParam(LLVMValueRef Fn);
	/**
	 * Obtain the last parameter to a function.<br>
	 * * @see llvm::Function::arg_end()
	 */
	LLVMValueRef LLVMGetLastParam(LLVMValueRef Fn);
	/**
	 * Obtain the next parameter to a function.<br>
	 * * This takes a LLVMValueRef obtained from LLVMGetFirstParam() (which is<br>
	 * actually a wrapped iterator) and obtains the next parameter from the<br>
	 * underlying iterator.
	 */
	LLVMValueRef LLVMGetNextParam(LLVMValueRef Arg);
	/**
	 * Obtain the previous parameter to a function.<br>
	 * * This is the opposite of LLVMGetNextParam().
	 */
	LLVMValueRef LLVMGetPreviousParam(LLVMValueRef Arg);
	/**
	 * Add an attribute to a function argument.<br>
	 * * @see llvm::Argument::addAttr()
	 */
	void LLVMAddAttribute(LLVMValueRef Arg, LLVMAttribute PA);
	/**
	 * Remove an attribute from a function argument.<br>
	 * * @see llvm::Argument::removeAttr()
	 */
	void LLVMRemoveAttribute(LLVMValueRef Arg, LLVMAttribute PA);
	/// Get an attribute from a function argument.
	LLVMAttribute LLVMGetAttribute(LLVMValueRef Arg);
	/**
	 * Set the alignment for a function parameter.<br>
	 * * @see llvm::Argument::addAttr()<br>
	 * @see llvm::AttrBuilder::addAlignmentAttr()
	 */
	void LLVMSetParamAlignment(LLVMValueRef Arg, unsigned align);
	/**
	 * Obtain a MDString value from a context.<br>
	 * * The returned instance corresponds to the llvm::MDString class.<br>
	 * * The instance is specified by string data of a specified length. The<br>
	 * string content is copied, so the backing memory can be freed after<br>
	 * this function returns.
	 */
	LLVMValueRef LLVMMDStringInContext(LLVMContextRef C, const char* Str, unsigned SLen);
	/// Obtain a MDString value from the global context.
	LLVMValueRef LLVMMDString(const char* Str, unsigned SLen);
	/**
	 * Obtain a MDNode value from a context.<br>
	 * * The returned value corresponds to the llvm::MDNode class.
	 */
	LLVMValueRef LLVMMDNodeInContext(LLVMContextRef C, LLVMValueRef* Vals, unsigned Count);
	/// Obtain a MDNode value from the global context.
	LLVMValueRef LLVMMDNode(LLVMValueRef* Vals, unsigned Count);
	/**
	 * Obtain the underlying string from a MDString value.<br>
	 * * @param V Instance to obtain string from.<br>
	 * @param Len Memory address which will hold length of returned string.<br>
	 * @return String data in MDString.
	 */
	const char* LLVMGetMDString(LLVMValueRef V, unsigned* Len);
	/**
	 * Obtain the number of operands from an MDNode value.<br>
	 * * @param V MDNode to get number of operands from.<br>
	 * @return Number of operands of the MDNode.
	 */
	unsigned LLVMGetMDNodeNumOperands(LLVMValueRef V);
	/**
	 * Obtain the given MDNode's operands.<br>
	 * * The passed LLVMValueRef pointer should point to enough memory to hold all of<br>
	 * the operands of the given MDNode (see LLVMGetMDNodeNumOperands) as<br>
	 * LLVMValueRefs. This memory will be populated with the LLVMValueRefs of the<br>
	 * MDNode's operands.<br>
	 * * @param V MDNode to get the operands from.<br>
	 * @param Dest Destination array for operands.
	 */
	void LLVMGetMDNodeOperands(LLVMValueRef V, LLVMValueRef* Dest);
	/// Convert a basic block instance to a value type.
	LLVMValueRef LLVMBasicBlockAsValue(LLVMBasicBlockRef BB);
	/// Determine whether a LLVMValueRef is itself a basic block.
	LLVMBool LLVMValueIsBasicBlock(LLVMValueRef Val);
	/// Convert a LLVMValueRef to a LLVMBasicBlockRef instance.
	LLVMBasicBlockRef LLVMValueAsBasicBlock(LLVMValueRef Val);
	/**
	 * Obtain the function to which a basic block belongs.<br>
	 * * @see llvm::BasicBlock::getParent()
	 */
	LLVMValueRef LLVMGetBasicBlockParent(LLVMBasicBlockRef BB);
	/**
	 * Obtain the terminator instruction for a basic block.<br>
	 * * If the basic block does not have a terminator (it is not well-formed<br>
	 * if it doesn't), then NULL is returned.<br>
	 * * The returned LLVMValueRef corresponds to a llvm::TerminatorInst.<br>
	 * * @see llvm::BasicBlock::getTerminator()
	 */
	LLVMValueRef LLVMGetBasicBlockTerminator(LLVMBasicBlockRef BB);
	/**
	 * Obtain the number of basic blocks in a function.<br>
	 * * @param Fn Function value to operate on.
	 */
	unsigned LLVMCountBasicBlocks(LLVMValueRef Fn);
	/**
	 * Obtain all of the basic blocks in a function.<br>
	 * * This operates on a function value. The BasicBlocks parameter is a<br>
	 * pointer to a pre-allocated array of LLVMBasicBlockRef of at least<br>
	 * LLVMCountBasicBlocks() in length. This array is populated with<br>
	 * LLVMBasicBlockRef instances.
	 */
	void LLVMGetBasicBlocks(LLVMValueRef Fn, LLVMBasicBlockRef* BasicBlocks);
	/**
	 * Obtain the first basic block in a function.<br>
	 * * The returned basic block can be used as an iterator. You will likely<br>
	 * eventually call into LLVMGetNextBasicBlock() with it.<br>
	 * * @see llvm::Function::begin()
	 */
	LLVMBasicBlockRef LLVMGetFirstBasicBlock(LLVMValueRef Fn);
	/**
	 * Obtain the last basic block in a function.<br>
	 * * @see llvm::Function::end()
	 */
	LLVMBasicBlockRef LLVMGetLastBasicBlock(LLVMValueRef Fn);
	/// Advance a basic block iterator.
	LLVMBasicBlockRef LLVMGetNextBasicBlock(LLVMBasicBlockRef BB);
	/// Go backwards in a basic block iterator.
	LLVMBasicBlockRef LLVMGetPreviousBasicBlock(LLVMBasicBlockRef BB);
	/**
	 * Obtain the basic block that corresponds to the entry point of a<br>
	 * function.<br>
	 * * @see llvm::Function::getEntryBlock()
	 */
	LLVMBasicBlockRef LLVMGetEntryBasicBlock(LLVMValueRef Fn);
	/**
	 * Append a basic block to the end of a function.<br>
	 * * @see llvm::BasicBlock::Create()
	 */
	LLVMBasicBlockRef LLVMAppendBasicBlockInContext(LLVMContextRef C, LLVMValueRef Fn, const char* Name);
	/**
	 * Append a basic block to the end of a function using the global<br>
	 * context.<br>
	 * * @see llvm::BasicBlock::Create()
	 */
	LLVMBasicBlockRef LLVMAppendBasicBlock(LLVMValueRef Fn, const char* Name);
	/**
	 * Insert a basic block in a function before another basic block.<br>
	 * * The function to add to is determined by the function of the<br>
	 * passed basic block.<br>
	 * * @see llvm::BasicBlock::Create()
	 */
	LLVMBasicBlockRef LLVMInsertBasicBlockInContext(LLVMContextRef C, LLVMBasicBlockRef BB, const char* Name);
	/**
	 * Insert a basic block in a function using the global context.<br>
	 * * @see llvm::BasicBlock::Create()
	 */
	LLVMBasicBlockRef LLVMInsertBasicBlock(LLVMBasicBlockRef InsertBeforeBB, const char* Name);
	/**
	 * Remove a basic block from a function and delete it.<br>
	 * * This deletes the basic block from its containing function and deletes<br>
	 * the basic block itself.<br>
	 * * @see llvm::BasicBlock::eraseFromParent()
	 */
	void LLVMDeleteBasicBlock(LLVMBasicBlockRef BB);
	/**
	 * Remove a basic block from a function.<br>
	 * * This deletes the basic block from its containing function but keep<br>
	 * the basic block alive.<br>
	 * * @see llvm::BasicBlock::removeFromParent()
	 */
	void LLVMRemoveBasicBlockFromParent(LLVMBasicBlockRef BB);
	/**
	 * Move a basic block to before another one.<br>
	 * * @see llvm::BasicBlock::moveBefore()
	 */
	void LLVMMoveBasicBlockBefore(LLVMBasicBlockRef BB, LLVMBasicBlockRef MovePos);
	/**
	 * Move a basic block to after another one.<br>
	 * * @see llvm::BasicBlock::moveAfter()
	 */
	void LLVMMoveBasicBlockAfter(LLVMBasicBlockRef BB, LLVMBasicBlockRef MovePos);
	/**
	 * Obtain the first instruction in a basic block.<br>
	 * * The returned LLVMValueRef corresponds to a llvm::Instruction<br>
	 * instance.
	 */
	LLVMValueRef LLVMGetFirstInstruction(LLVMBasicBlockRef BB);
	/**
	 * Obtain the last instruction in a basic block.<br>
	 * * The returned LLVMValueRef corresponds to a LLVM:Instruction.
	 */
	LLVMValueRef LLVMGetLastInstruction(LLVMBasicBlockRef BB);
	/// Determine whether an instruction has any metadata attached.
	int LLVMHasMetadata(LLVMValueRef Val);
	/// Return metadata associated with an instruction value.
	LLVMValueRef LLVMGetMetadata(LLVMValueRef Val, unsigned KindID);
	/// Set metadata associated with an instruction value.
	void LLVMSetMetadata(LLVMValueRef Val, unsigned KindID, LLVMValueRef Node);
	/**
	 * Obtain the basic block to which an instruction belongs.<br>
	 * * @see llvm::Instruction::getParent()
	 */
	LLVMBasicBlockRef LLVMGetInstructionParent(LLVMValueRef Inst);
	/**
	 * Obtain the instruction that occurs after the one specified.<br>
	 * * The next instruction will be from the same basic block.<br>
	 * * If this is the last instruction in a basic block, NULL will be<br>
	 * returned.
	 */
	LLVMValueRef LLVMGetNextInstruction(LLVMValueRef Inst);
	/**
	 * Obtain the instruction that occurred before this one.<br>
	 * * If the instruction is the first instruction in a basic block, NULL<br>
	 * will be returned.
	 */
	LLVMValueRef LLVMGetPreviousInstruction(LLVMValueRef Inst);
	/**
	 * Remove and delete an instruction.<br>
	 * * The instruction specified is removed from its containing building<br>
	 * block and then deleted.<br>
	 * * @see llvm::Instruction::eraseFromParent()
	 */
	void LLVMInstructionEraseFromParent(LLVMValueRef Inst);
	/**
	 * Obtain the code opcode for an individual instruction.<br>
	 * * @see llvm::Instruction::getOpCode()
	 */
	LLVMOpcode LLVMGetInstructionOpcode(LLVMValueRef Inst);
	/**
	 * Obtain the predicate of an instruction.<br>
	 * * This is only valid for instructions that correspond to llvm::ICmpInst<br>
	 * or llvm::ConstantExpr whose opcode is llvm::Instruction::ICmp.<br>
	 * * @see llvm::ICmpInst::getPredicate()
	 */
	LLVMIntPredicate LLVMGetICmpPredicate(LLVMValueRef Inst);
	/**
	 * Set the calling convention for a call instruction.<br>
	 * * This expects an LLVMValueRef that corresponds to a llvm::CallInst or<br>
	 * llvm::InvokeInst.<br>
	 * * @see llvm::CallInst::setCallingConv()<br>
	 * @see llvm::InvokeInst::setCallingConv()
	 */
	void LLVMSetInstructionCallConv(LLVMValueRef Instr, unsigned CC);
	/**
	 * Obtain the calling convention for a call instruction.<br>
	 * * This is the opposite of LLVMSetInstructionCallConv(). Reads its<br>
	 * usage.<br>
	 * * @see LLVMSetInstructionCallConv()
	 */
	unsigned LLVMGetInstructionCallConv(LLVMValueRef Instr);
	void LLVMAddInstrAttribute(LLVMValueRef Instr, unsigned index, LLVMAttribute);
	void LLVMRemoveInstrAttribute(LLVMValueRef Instr, unsigned index, LLVMAttribute);
	void LLVMSetInstrParamAlignment(LLVMValueRef Instr, unsigned index, unsigned align);
	/**
	 * Obtain whether a call instruction is a tail call.<br>
	 * * This only works on llvm::CallInst instructions.<br>
	 * * @see llvm::CallInst::isTailCall()
	 */
	LLVMBool LLVMIsTailCall(LLVMValueRef CallInst);
	/**
	 * Set whether a call instruction is a tail call.<br>
	 * * This only works on llvm::CallInst instructions.<br>
	 * * @see llvm::CallInst::setTailCall()
	 */
	void LLVMSetTailCall(LLVMValueRef CallInst, LLVMBool IsTailCall);
	/**
	 * Obtain the default destination basic block of a switch instruction.<br>
	 * * This only works on llvm::SwitchInst instructions.<br>
	 * * @see llvm::SwitchInst::getDefaultDest()
	 */
	LLVMBasicBlockRef LLVMGetSwitchDefaultDest(LLVMValueRef SwitchInstr);
	/// Add an incoming value to the end of a PHI list.
	void LLVMAddIncoming(LLVMValueRef PhiNode, LLVMValueRef* IncomingValues, LLVMBasicBlockRef* IncomingBlocks, unsigned Count);
	/// Obtain the number of incoming basic blocks to a PHI node.
	unsigned LLVMCountIncoming(LLVMValueRef PhiNode);
	/// Obtain an incoming value to a PHI node as a LLVMValueRef.
	LLVMValueRef LLVMGetIncomingValue(LLVMValueRef PhiNode, unsigned Index);
	/// Obtain an incoming value to a PHI node as a LLVMBasicBlockRef.
	LLVMBasicBlockRef LLVMGetIncomingBlock(LLVMValueRef PhiNode, unsigned Index);
	LLVMBuilderRef LLVMCreateBuilderInContext(LLVMContextRef C);
	LLVMBuilderRef LLVMCreateBuilder();
	void LLVMPositionBuilder(LLVMBuilderRef Builder, LLVMBasicBlockRef Block, LLVMValueRef Instr);
	void LLVMPositionBuilderBefore(LLVMBuilderRef Builder, LLVMValueRef Instr);
	void LLVMPositionBuilderAtEnd(LLVMBuilderRef Builder, LLVMBasicBlockRef Block);
	LLVMBasicBlockRef LLVMGetInsertBlock(LLVMBuilderRef Builder);
	void LLVMClearInsertionPosition(LLVMBuilderRef Builder);
	void LLVMInsertIntoBuilder(LLVMBuilderRef Builder, LLVMValueRef Instr);
	void LLVMInsertIntoBuilderWithName(LLVMBuilderRef Builder, LLVMValueRef Instr, const char* Name);
	void LLVMDisposeBuilder(LLVMBuilderRef Builder);
	/// Metadata
	void LLVMSetCurrentDebugLocation(LLVMBuilderRef Builder, LLVMValueRef L);
	LLVMValueRef LLVMGetCurrentDebugLocation(LLVMBuilderRef Builder);
	void LLVMSetInstDebugLocation(LLVMBuilderRef Builder, LLVMValueRef Inst);
	/// Terminators
	LLVMValueRef LLVMBuildRetVoid(LLVMBuilderRef);
	LLVMValueRef LLVMBuildRet(LLVMBuilderRef, LLVMValueRef V);
	LLVMValueRef LLVMBuildAggregateRet(LLVMBuilderRef, LLVMValueRef* RetVals, unsigned N);
	LLVMValueRef LLVMBuildBr(LLVMBuilderRef, LLVMBasicBlockRef Dest);
	LLVMValueRef LLVMBuildCondBr(LLVMBuilderRef, LLVMValueRef If, LLVMBasicBlockRef Then, LLVMBasicBlockRef Else);
	LLVMValueRef LLVMBuildSwitch(LLVMBuilderRef, LLVMValueRef V, LLVMBasicBlockRef Else, unsigned NumCases);
	LLVMValueRef LLVMBuildIndirectBr(LLVMBuilderRef B, LLVMValueRef Addr, unsigned NumDests);
	LLVMValueRef LLVMBuildInvoke(LLVMBuilderRef, LLVMValueRef Fn, LLVMValueRef* Args, unsigned NumArgs, LLVMBasicBlockRef Then, LLVMBasicBlockRef Catch, const char* Name);
	LLVMValueRef LLVMBuildLandingPad(LLVMBuilderRef B, LLVMTypeRef Ty, LLVMValueRef PersFn, unsigned NumClauses, const char* Name);
	LLVMValueRef LLVMBuildResume(LLVMBuilderRef B, LLVMValueRef Exn);
	LLVMValueRef LLVMBuildUnreachable(LLVMBuilderRef);
	/// Add a case to the switch instruction
	void LLVMAddCase(LLVMValueRef Switch, LLVMValueRef OnVal, LLVMBasicBlockRef Dest);
	/// Add a destination to the indirectbr instruction
	void LLVMAddDestination(LLVMValueRef IndirectBr, LLVMBasicBlockRef Dest);
	/// Add a catch or filter clause to the landingpad instruction
	void LLVMAddClause(LLVMValueRef LandingPad, LLVMValueRef ClauseVal);
	/// Set the 'cleanup' flag in the landingpad instruction
	void LLVMSetCleanup(LLVMValueRef LandingPad, LLVMBool Val);
	/// Arithmetic
	LLVMValueRef LLVMBuildAdd(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildNSWAdd(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildNUWAdd(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildFAdd(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildSub(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildNSWSub(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildNUWSub(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildFSub(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildMul(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildNSWMul(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildNUWMul(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildFMul(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildUDiv(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildSDiv(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildExactSDiv(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildFDiv(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildURem(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildSRem(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildFRem(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildShl(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildLShr(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildAShr(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildAnd(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildOr(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildXor(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildBinOp(LLVMBuilderRef B, LLVMOpcode Op, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildNeg(LLVMBuilderRef, LLVMValueRef V, const char* Name);
	LLVMValueRef LLVMBuildNSWNeg(LLVMBuilderRef B, LLVMValueRef V, const char* Name);
	LLVMValueRef LLVMBuildNUWNeg(LLVMBuilderRef B, LLVMValueRef V, const char* Name);
	LLVMValueRef LLVMBuildFNeg(LLVMBuilderRef, LLVMValueRef V, const char* Name);
	LLVMValueRef LLVMBuildNot(LLVMBuilderRef, LLVMValueRef V, const char* Name);
	/// Memory
	LLVMValueRef LLVMBuildMalloc(LLVMBuilderRef, LLVMTypeRef Ty, const char* Name);
	LLVMValueRef LLVMBuildArrayMalloc(LLVMBuilderRef, LLVMTypeRef Ty, LLVMValueRef Val, const char* Name);
	LLVMValueRef LLVMBuildAlloca(LLVMBuilderRef, LLVMTypeRef Ty, const char* Name);
	LLVMValueRef LLVMBuildArrayAlloca(LLVMBuilderRef, LLVMTypeRef Ty, LLVMValueRef Val, const char* Name);
	LLVMValueRef LLVMBuildFree(LLVMBuilderRef, LLVMValueRef PointerVal);
	LLVMValueRef LLVMBuildLoad(LLVMBuilderRef, LLVMValueRef PointerVal, const char* Name);
	LLVMValueRef LLVMBuildStore(LLVMBuilderRef, LLVMValueRef Val, LLVMValueRef Ptr);
	LLVMValueRef LLVMBuildGEP(LLVMBuilderRef B, LLVMValueRef Pointer, LLVMValueRef* Indices, unsigned NumIndices, const char* Name);
	LLVMValueRef LLVMBuildInBoundsGEP(LLVMBuilderRef B, LLVMValueRef Pointer, LLVMValueRef* Indices, unsigned NumIndices, const char* Name);
	LLVMValueRef LLVMBuildStructGEP(LLVMBuilderRef B, LLVMValueRef Pointer, unsigned Idx, const char* Name);
	LLVMValueRef LLVMBuildGlobalString(LLVMBuilderRef B, const char* Str, const char* Name);
	LLVMValueRef LLVMBuildGlobalStringPtr(LLVMBuilderRef B, const char* Str, const char* Name);
	LLVMBool LLVMGetVolatile(LLVMValueRef MemoryAccessInst);
	void LLVMSetVolatile(LLVMValueRef MemoryAccessInst, LLVMBool IsVolatile);
	/// Casts
	LLVMValueRef LLVMBuildTrunc(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildZExt(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildSExt(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildFPToUI(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildFPToSI(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildUIToFP(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildSIToFP(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildFPTrunc(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildFPExt(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildPtrToInt(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildIntToPtr(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildBitCast(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildZExtOrBitCast(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildSExtOrBitCast(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildTruncOrBitCast(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildCast(LLVMBuilderRef B, LLVMOpcode Op, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildPointerCast(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	LLVMValueRef LLVMBuildIntCast(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name); /*Signed cast!*/
	LLVMValueRef LLVMBuildFPCast(LLVMBuilderRef, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Comparisons
	LLVMValueRef LLVMBuildICmp(LLVMBuilderRef, LLVMIntPredicate Op, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildFCmp(LLVMBuilderRef, LLVMRealPredicate Op, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Miscellaneous instructions
	LLVMValueRef LLVMBuildPhi(LLVMBuilderRef, LLVMTypeRef Ty, const char* Name);
	LLVMValueRef LLVMBuildCall(LLVMBuilderRef, LLVMValueRef Fn, LLVMValueRef* Args, unsigned NumArgs, const char* Name);
	LLVMValueRef LLVMBuildSelect(LLVMBuilderRef, LLVMValueRef If, LLVMValueRef Then, LLVMValueRef Else, const char* Name);
	LLVMValueRef LLVMBuildVAArg(LLVMBuilderRef, LLVMValueRef List, LLVMTypeRef Ty, const char* Name);
	LLVMValueRef LLVMBuildExtractElement(LLVMBuilderRef, LLVMValueRef VecVal, LLVMValueRef Index, const char* Name);
	LLVMValueRef LLVMBuildInsertElement(LLVMBuilderRef, LLVMValueRef VecVal, LLVMValueRef EltVal, LLVMValueRef Index, const char* Name);
	LLVMValueRef LLVMBuildShuffleVector(LLVMBuilderRef, LLVMValueRef V1, LLVMValueRef V2, LLVMValueRef Mask, const char* Name);
	LLVMValueRef LLVMBuildExtractValue(LLVMBuilderRef, LLVMValueRef AggVal, unsigned Index, const char* Name);
	LLVMValueRef LLVMBuildInsertValue(LLVMBuilderRef, LLVMValueRef AggVal, LLVMValueRef EltVal, unsigned Index, const char* Name);
	LLVMValueRef LLVMBuildIsNull(LLVMBuilderRef, LLVMValueRef Val, const char* Name);
	LLVMValueRef LLVMBuildIsNotNull(LLVMBuilderRef, LLVMValueRef Val, const char* Name);
	LLVMValueRef LLVMBuildPtrDiff(LLVMBuilderRef, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	LLVMValueRef LLVMBuildAtomicRMW(LLVMBuilderRef B, LLVMAtomicRMWBinOp op, LLVMValueRef PTR, LLVMValueRef Val, LLVMAtomicOrdering ordering, LLVMBool singleThread);
	/**
	 * Changes the type of M so it can be passed to FunctionPassManagers and the<br>
	 * JIT.  They take ModuleProviders for historical reasons.
	 */
	LLVMModuleProviderRef LLVMCreateModuleProviderForExistingModule(LLVMModuleRef M);
	/// Destroys the module M.
	void LLVMDisposeModuleProvider(LLVMModuleProviderRef M);
	LLVMBool LLVMCreateMemoryBufferWithContentsOfFile(const char* Path, LLVMMemoryBufferRef* OutMemBuf, char** OutMessage);
	LLVMBool LLVMCreateMemoryBufferWithSTDIN(LLVMMemoryBufferRef* OutMemBuf, char** OutMessage);
	LLVMMemoryBufferRef LLVMCreateMemoryBufferWithMemoryRange(const char* InputData, size_t InputDataLength, const char* BufferName, LLVMBool RequiresNullTerminator);
	LLVMMemoryBufferRef LLVMCreateMemoryBufferWithMemoryRangeCopy(const char* InputData, size_t InputDataLength, const char* BufferName);
	const char* LLVMGetBufferStart(LLVMMemoryBufferRef MemBuf);
	size_t LLVMGetBufferSize(LLVMMemoryBufferRef MemBuf);
	void LLVMDisposeMemoryBuffer(LLVMMemoryBufferRef MemBuf);
	/**
	 * Return the global pass registry, for use with initialization functions.<br>
	 * @see llvm::PassRegistry::getPassRegistry
	 */
	LLVMPassRegistryRef LLVMGetGlobalPassRegistry();
	/**
	 * Constructs a new whole-module pass pipeline. This type of pipeline is<br>
	 * suitable for link-time optimization and whole-module transformations.<br>
	 * @see llvm::PassManager::PassManager
	 */
	LLVMPassManagerRef LLVMCreatePassManager();
	/**
	 * Constructs a new function-by-function pass pipeline over the module<br>
	 * provider. It does not take ownership of the module provider. This type of<br>
	 * pipeline is suitable for code generation and JIT compilation tasks.<br>
	 * @see llvm::FunctionPassManager::FunctionPassManager
	 */
	LLVMPassManagerRef LLVMCreateFunctionPassManagerForModule(LLVMModuleRef M);
	/// Deprecated: Use LLVMCreateFunctionPassManagerForModule instead.
	LLVMPassManagerRef LLVMCreateFunctionPassManager(LLVMModuleProviderRef MP);
	/**
	 * Initializes, executes on the provided module, and finalizes all of the<br>
	 * passes scheduled in the pass manager. Returns 1 if any of the passes<br>
	 * modified the module, 0 otherwise.<br>
	 * @see llvm::PassManager::run(Module&)
	 */
	LLVMBool LLVMRunPassManager(LLVMPassManagerRef PM, LLVMModuleRef M);
	/**
	 * Initializes all of the function passes scheduled in the function pass<br>
	 * manager. Returns 1 if any of the passes modified the module, 0 otherwise.<br>
	 * @see llvm::FunctionPassManager::doInitialization
	 */
	LLVMBool LLVMInitializeFunctionPassManager(LLVMPassManagerRef FPM);
	/**
	 * Executes all of the function passes scheduled in the function pass manager<br>
	 * on the provided function. Returns 1 if any of the passes modified the<br>
	 * function, false otherwise.<br>
	 * @see llvm::FunctionPassManager::run(Function&)
	 */
	LLVMBool LLVMRunFunctionPassManager(LLVMPassManagerRef FPM, LLVMValueRef F);
	/**
	 * Finalizes all of the function passes scheduled in in the function pass<br>
	 * manager. Returns 1 if any of the passes modified the module, 0 otherwise.<br>
	 * @see llvm::FunctionPassManager::doFinalization
	 */
	LLVMBool LLVMFinalizeFunctionPassManager(LLVMPassManagerRef FPM);
	/**
	 * Frees the memory of a pass pipeline. For function pipelines, does not free<br>
	 * the module provider.<br>
	 * @see llvm::PassManagerBase::~PassManagerBase.
	 */
	void LLVMDisposePassManager(LLVMPassManagerRef PM);
	/**
	 * Allocate and initialize structures needed to make LLVM safe for<br>
	 * multithreading. The return value indicates whether multithreaded<br>
	 * initialization succeeded. Must be executed in isolation from all<br>
	 * other LLVM api calls.<br>
	 * @see llvm::llvm_start_multithreaded
	 */
	LLVMBool LLVMStartMultithreaded();
	/**
	 * Deallocate structures necessary to make LLVM safe for multithreading.<br>
	 * Must be executed in isolation from all other LLVM api calls.<br>
	 * @see llvm::llvm_stop_multithreaded
	 */
	void LLVMStopMultithreaded();
	/**
	 * Check whether LLVM is executing in thread-safe mode or not.<br>
	 * @see llvm::llvm_is_multithreaded
	 */
	LLVMBool LLVMIsMultithreaded();
}




extern ""C"" {

}

extern ""C"" {
typedef unsigned int uintptr_t;
	typedef char *va_list;
}
typedef unsigned int size_t;
typedef size_t rsize_t;
typedef int intptr_t;
typedef int ptrdiff_t;
typedef unsigned short wint_t;
typedef unsigned short wctype_t;
extern ""C"" {
extern __cdecl int* _errno();
	__cdecl errno_t _set_errno(int _Value);
	__cdecl errno_t _get_errno(int* _Value);
}
/// An opaque reference to a disassembler context.
typedef void *LLVMDisasmContextRef;
/**
 * The type for the operand information call back function.  This is called to<br>
 * get the symbolic information for an operand of an instruction.  Typically<br>
 * this is from the relocation information, symbol table, etc.  That block of<br>
 * information is saved when the disassembler context is created and passed to<br>
 * the call back in the DisInfo parameter.  The instruction containing operand<br>
 * is at the PC parameter.  For some instruction sets, there can be more than<br>
 * one operand with symbolic information.  To determine the symbolic operand<br>
 * information for each operand, the bytes for the specific operand in the<br>
 * instruction are specified by the Offset parameter and its byte widith is the<br>
 * size parameter.  For instructions sets with fixed widths and one symbolic<br>
 * operand per instruction, the Offset parameter will be zero and Size parameter<br>
 * will be the instruction width.  The information is returned in TagBuf and is <br>
 * Triple specific with its specific information defined by the value of<br>
 * TagType for that Triple.  If symbolic information is returned the function<br>
 * returns 1, otherwise it returns 0.
 */
typedef int (*LLVMOpInfoCallback)(void* DisInfo, uint64_t PC, uint64_t Offset, uint64_t Size, int TagType, void* TagBuf);
/**
 * The initial support in LLVM MC for the most general form of a relocatable<br>
 * expression is "AddSymbol - SubtractSymbol + Offset".  For some Darwin targets<br>
 * this full form is encoded in the relocation information so that AddSymbol and<br>
 * SubtractSymbol can be link edited independent of each other.  Many other<br>
 * platforms only allow a relocatable expression of the form AddSymbol + Offset<br>
 * to be encoded.<br>
 * <br>
 * The LLVMOpInfoCallback() for the TagType value of 1 uses the struct<br>
 * LLVMOpInfo1.  The value of the relocatable expression for the operand,<br>
 * including any PC adjustment, is passed in to the call back in the Value<br>
 * field.  The symbolic information about the operand is returned using all<br>
 * the fields of the structure with the Offset of the relocatable expression<br>
 * returned in the Value field.  It is possible that some symbols in the<br>
 * relocatable expression were assembly temporary symbols, for example<br>
 * "Ldata - LpicBase + constant", and only the Values of the symbols without<br>
 * symbol names are present in the relocation information.  The VariantKind<br>
 * type is one of the Target specific #defines below and is used to print<br>
 * operands like "_foo@GOT", ":lower16:_foo", etc.
 */
struct LLVMOpInfoSymbol1 {
	uint64_t Present; /* 1 if this symbol is present */
	const char *Name; /* symbol name if not NULL */
	uint64_t Value; /* symbol value if name is NULL */
};
struct LLVMOpInfo1 {
	struct LLVMOpInfoSymbol1 AddSymbol;
	struct LLVMOpInfoSymbol1 SubtractSymbol;
	uint64_t Value;
	uint64_t VariantKind;
};
/**
 * The type for the symbol lookup function.  This may be called by the<br>
 * disassembler for things like adding a comment for a PC plus a constant<br>
 * offset load instruction to use a symbol name instead of a load address value.<br>
 * It is passed the block information is saved when the disassembler context is<br>
 * created and the ReferenceValue to look up as a symbol.  If no symbol is found<br>
 * for the ReferenceValue NULL is returned.  The ReferenceType of the<br>
 * instruction is passed indirectly as is the PC of the instruction in<br>
 * ReferencePC.  If the output reference can be determined its type is returned<br>
 * indirectly in ReferenceType along with ReferenceName if any, or that is set<br>
 * to NULL.
 */
typedef const char *(*LLVMSymbolLookupCallback)(void* DisInfo, uint64_t ReferenceValue, uint64_t* ReferenceType, uint64_t ReferencePC, const char** ReferenceName);
extern ""C"" {
/**
	 * Create a disassembler for the TripleName.  Symbolic disassembly is supported<br>
	 * by passing a block of information in the DisInfo parameter and specifying the<br>
	 * TagType and callback functions as described above.  These can all be passed<br>
	 * as NULL.  If successful, this returns a disassembler context.  If not, it<br>
	 * returns NULL. This function is equivalent to calling LLVMCreateDisasmCPU()<br>
	 * with an empty CPU name.
	 */
	LLVMDisasmContextRef LLVMCreateDisasm(const char* TripleName, void* DisInfo, int TagType, LLVMOpInfoCallback GetOpInfo, LLVMSymbolLookupCallback SymbolLookUp);
	/**
	 * Create a disassembler for the TripleName and a specific CPU.  Symbolic<br>
	 * disassembly is supported by passing a block of information in the DisInfo<br>
	 * parameter and specifying the TagType and callback functions as described<br>
	 * above.  These can all be passed * as NULL.  If successful, this returns a<br>
	 * disassembler context.  If not, it returns NULL.
	 */
	LLVMDisasmContextRef LLVMCreateDisasmCPU(const char* Triple, const char* CPU, void* DisInfo, int TagType, LLVMOpInfoCallback GetOpInfo, LLVMSymbolLookupCallback SymbolLookUp);
	/**
	 * Set the disassembler's options.  Returns 1 if it can set the Options and 0<br>
	 * otherwise.
	 */
	int LLVMSetDisasmOptions(LLVMDisasmContextRef DC, uint64_t Options);
	/// Dispose of a disassembler context.
	void LLVMDisasmDispose(LLVMDisasmContextRef DC);
	/**
	 * Disassemble a single instruction using the disassembler context specified in<br>
	 * the parameter DC.  The bytes of the instruction are specified in the<br>
	 * parameter Bytes, and contains at least BytesSize number of bytes.  The<br>
	 * instruction is at the address specified by the PC parameter.  If a valid<br>
	 * instruction can be disassembled, its string is returned indirectly in<br>
	 * OutString whose size is specified in the parameter OutStringSize.  This<br>
	 * function returns the number of bytes in the instruction or zero if there was<br>
	 * no valid instruction.
	 */
	size_t LLVMDisasmInstruction(LLVMDisasmContextRef DC, uint8_t* Bytes, uint64_t BytesSize, uint64_t PC, char* OutString, size_t OutStringSize);
}



extern ""C"" {
void LLVMLinkInJIT();
	void LLVMLinkInMCJIT();
	void LLVMLinkInInterpreter();
	typedef struct LLVMOpaqueGenericValue *LLVMGenericValueRef;
	typedef struct LLVMOpaqueExecutionEngine *LLVMExecutionEngineRef;
	struct LLVMMCJITCompilerOptions {
		unsigned OptLevel;
		LLVMCodeModel CodeModel;
		LLVMBool NoFramePointerElim;
		LLVMBool EnableFastISel;
	};
	LLVMGenericValueRef LLVMCreateGenericValueOfInt(LLVMTypeRef Ty, unsigned long long N, LLVMBool IsSigned);
	LLVMGenericValueRef LLVMCreateGenericValueOfPointer(void* P);
	LLVMGenericValueRef LLVMCreateGenericValueOfFloat(LLVMTypeRef Ty, double N);
	unsigned LLVMGenericValueIntWidth(LLVMGenericValueRef GenValRef);
	unsigned long long LLVMGenericValueToInt(LLVMGenericValueRef GenVal, LLVMBool IsSigned);
	void* LLVMGenericValueToPointer(LLVMGenericValueRef GenVal);
	double LLVMGenericValueToFloat(LLVMTypeRef TyRef, LLVMGenericValueRef GenVal);
	void LLVMDisposeGenericValue(LLVMGenericValueRef GenVal);
	LLVMBool LLVMCreateExecutionEngineForModule(LLVMExecutionEngineRef* OutEE, LLVMModuleRef M, char** OutError);
	LLVMBool LLVMCreateInterpreterForModule(LLVMExecutionEngineRef* OutInterp, LLVMModuleRef M, char** OutError);
	LLVMBool LLVMCreateJITCompilerForModule(LLVMExecutionEngineRef* OutJIT, LLVMModuleRef M, unsigned OptLevel, char** OutError);
	void LLVMInitializeMCJITCompilerOptions(struct LLVMMCJITCompilerOptions* Options, size_t SizeOfOptions);
	/**
	 * Create an MCJIT execution engine for a module, with the given options. It is<br>
	 * the responsibility of the caller to ensure that all fields in Options up to<br>
	 * the given SizeOfOptions are initialized. It is correct to pass a smaller<br>
	 * value of SizeOfOptions that omits some fields. The canonical way of using<br>
	 * this is:<br>
	 * * LLVMMCJITCompilerOptions options;<br>
	 * LLVMInitializeMCJITCompilerOptions(&options, sizeof(options));<br>
	 * ... fill in those options you care about<br>
	 * LLVMCreateMCJITCompilerForModule(&jit, mod, &options, sizeof(options),<br>
	 *                                  &error);<br>
	 * * Note that this is also correct, though possibly suboptimal:<br>
	 * * LLVMCreateMCJITCompilerForModule(&jit, mod, 0, 0, &error);
	 */
	LLVMBool LLVMCreateMCJITCompilerForModule(LLVMExecutionEngineRef* OutJIT, LLVMModuleRef M, struct LLVMMCJITCompilerOptions* Options, size_t SizeOfOptions, char** OutError);
	/// Deprecated: Use LLVMCreateExecutionEngineForModule instead.
	LLVMBool LLVMCreateExecutionEngine(LLVMExecutionEngineRef* OutEE, LLVMModuleProviderRef MP, char** OutError);
	/// Deprecated: Use LLVMCreateInterpreterForModule instead.
	LLVMBool LLVMCreateInterpreter(LLVMExecutionEngineRef* OutInterp, LLVMModuleProviderRef MP, char** OutError);
	/// Deprecated: Use LLVMCreateJITCompilerForModule instead.
	LLVMBool LLVMCreateJITCompiler(LLVMExecutionEngineRef* OutJIT, LLVMModuleProviderRef MP, unsigned OptLevel, char** OutError);
	void LLVMDisposeExecutionEngine(LLVMExecutionEngineRef EE);
	void LLVMRunStaticConstructors(LLVMExecutionEngineRef EE);
	void LLVMRunStaticDestructors(LLVMExecutionEngineRef EE);
	int LLVMRunFunctionAsMain(LLVMExecutionEngineRef EE, LLVMValueRef F, unsigned ArgC, const const char** ArgV, const const char** EnvP);
	LLVMGenericValueRef LLVMRunFunction(LLVMExecutionEngineRef EE, LLVMValueRef F, unsigned NumArgs, LLVMGenericValueRef* Args);
	void LLVMFreeMachineCodeForFunction(LLVMExecutionEngineRef EE, LLVMValueRef F);
	void LLVMAddModule(LLVMExecutionEngineRef EE, LLVMModuleRef M);
	/// Deprecated: Use LLVMAddModule instead.
	void LLVMAddModuleProvider(LLVMExecutionEngineRef EE, LLVMModuleProviderRef MP);
	LLVMBool LLVMRemoveModule(LLVMExecutionEngineRef EE, LLVMModuleRef M, LLVMModuleRef* OutMod, char** OutError);
	/// Deprecated: Use LLVMRemoveModule instead.
	LLVMBool LLVMRemoveModuleProvider(LLVMExecutionEngineRef EE, LLVMModuleProviderRef MP, LLVMModuleRef* OutMod, char** OutError);
	LLVMBool LLVMFindFunction(LLVMExecutionEngineRef EE, const char* Name, LLVMValueRef* OutFn);
	void* LLVMRecompileAndRelinkFunction(LLVMExecutionEngineRef EE, LLVMValueRef Fn);
	LLVMTargetDataRef LLVMGetExecutionEngineTargetData(LLVMExecutionEngineRef EE);
	void LLVMAddGlobalMapping(LLVMExecutionEngineRef EE, LLVMValueRef Global, void* Addr);
	void* LLVMGetPointerToGlobal(LLVMExecutionEngineRef EE, LLVMValueRef Global);
}
