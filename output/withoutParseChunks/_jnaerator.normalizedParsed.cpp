extern ""C"" {
typedef int LLVMBool;
	/// The top-level container for all LLVM global data. See the LLVMContext class.
	typedef LLVMOpaqueContext* LLVMContextRef;
	/**
	 * The top-level container for all other LLVM Intermediate Representation (IR)<br>
	 * objects.<br>
	 * * @see llvm::Module
	 */
	typedef LLVMOpaqueModule* LLVMModuleRef;
	/**
	 * Each value in the LLVM IR has a type, an LLVMTypeRef.<br>
	 * * @see llvm::Type
	 */
	typedef LLVMOpaqueType* LLVMTypeRef;
	/**
	 * Represents an individual value in LLVM IR.<br>
	 * * This models llvm::Value.
	 */
	typedef LLVMOpaqueValue* LLVMValueRef;
	/**
	 * Represents a basic block of instructions in LLVM IR.<br>
	 * * This models llvm::BasicBlock.
	 */
	typedef LLVMOpaqueBasicBlock* LLVMBasicBlockRef;
	/**
	 * Represents an LLVM basic block builder.<br>
	 * * This models llvm::IRBuilder.
	 */
	typedef LLVMOpaqueBuilder* LLVMBuilderRef;
	/**
	 * Interface used to provide a module to JIT or interpreter.<br>
	 * This is now just a synonym for llvm::Module, but we have to keep using the<br>
	 * different type to keep binary compatibility.
	 */
	typedef LLVMOpaqueModuleProvider* LLVMModuleProviderRef;
	/**
	 * Used to provide a module to JIT or interpreter.<br>
	 * * @see llvm::MemoryBuffer
	 */
	typedef LLVMOpaqueMemoryBuffer* LLVMMemoryBufferRef;
	/// @see llvm::PassManagerBase
	typedef LLVMOpaquePassManager* LLVMPassManagerRef;
	/// @see llvm::PassRegistry
	typedef LLVMOpaquePassRegistry* LLVMPassRegistryRef;
	/**
	 * Used to get the users and usees of a Value.<br>
	 * * @see llvm::Use
	 */
	typedef LLVMOpaqueUse* LLVMUseRef;
	typedef enum LLVMAttribute {
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
	typedef enum LLVMOpcode {
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
	typedef enum LLVMTypeKind {
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
	typedef enum LLVMLinkage {
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
	typedef enum LLVMVisibility {
		LLVMDefaultVisibility /**< The GV is visible */,
		LLVMHiddenVisibility /**< The GV is hidden */,
		LLVMProtectedVisibility /**< The GV is protected */
	} LLVMVisibility;
	typedef enum LLVMCallConv {
		LLVMCCallConv = 0,
		LLVMFastCallConv = 8,
		LLVMColdCallConv = 9,
		LLVMX86StdcallCallConv = 64,
		LLVMX86FastcallCallConv = 65
	} LLVMCallConv;
	typedef enum LLVMIntPredicate {
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
	typedef enum LLVMRealPredicate {
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
	typedef enum LLVMLandingPadClauseTy {
		LLVMLandingPadCatch /**< A catch clause   */,
		LLVMLandingPadFilter /**< A filter clause  */
	} LLVMLandingPadClauseTy;
	typedef enum LLVMThreadLocalMode {
		LLVMNotThreadLocal = 0,
		LLVMGeneralDynamicTLSModel,
		LLVMLocalDynamicTLSModel,
		LLVMInitialExecTLSModel,
		LLVMLocalExecTLSModel
	} LLVMThreadLocalMode;
	typedef enum LLVMAtomicOrdering {
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
	typedef enum LLVMAtomicRMWBinOp {
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
	/// Original signature : <code>void LLVMInitializeCore(LLVMPassRegistryRef)</code>
	void LLVMInitializeCore(LLVMPassRegistryRef R);
	/**
	 * Deallocate and destroy all ManagedStatic variables.<br>
	 * @see llvm::llvm_shutdown<br>
	 * @see ManagedStatic<br>
	 * Original signature : <code>void LLVMShutdown()</code>
	 */
	void LLVMShutdown();
	/// Original signature : <code>void LLVMDisposeMessage(char*)</code>
	void LLVMDisposeMessage(char* Message);
	/**
	 * Create a new context.<br>
	 * * Every call to this function should be paired with a call to<br>
	 * LLVMContextDispose() or the context will leak memory.<br>
	 * Original signature : <code>LLVMContextRef LLVMContextCreate()</code>
	 */
	LLVMContextRef LLVMContextCreate();
	/**
	 * Obtain the global context instance.<br>
	 * Original signature : <code>LLVMContextRef LLVMGetGlobalContext()</code>
	 */
	LLVMContextRef LLVMGetGlobalContext();
	/**
	 * Destroy a context instance.<br>
	 * * This should be called for every call to LLVMContextCreate() or memory<br>
	 * will be leaked.<br>
	 * Original signature : <code>void LLVMContextDispose(LLVMContextRef)</code>
	 */
	void LLVMContextDispose(LLVMContextRef C);
	/// Original signature : <code>int LLVMGetMDKindIDInContext(LLVMContextRef, const char*, unsigned)</code>
	unsigned int LLVMGetMDKindIDInContext(LLVMContextRef C, const char* Name, unsigned SLen);
	/// Original signature : <code>int LLVMGetMDKindID(const char*, unsigned)</code>
	unsigned int LLVMGetMDKindID(const char* Name, unsigned SLen);
	/**
	 * Create a new, empty module in the global context.<br>
	 * * This is equivalent to calling LLVMModuleCreateWithNameInContext with<br>
	 * LLVMGetGlobalContext() as the context parameter.<br>
	 * * Every invocation should be paired with LLVMDisposeModule() or memory<br>
	 * will be leaked.<br>
	 * Original signature : <code>LLVMModuleRef LLVMModuleCreateWithName(const char*)</code>
	 */
	LLVMModuleRef LLVMModuleCreateWithName(const char* ModuleID);
	/**
	 * Create a new, empty module in a specific context.<br>
	 * * Every invocation should be paired with LLVMDisposeModule() or memory<br>
	 * will be leaked.<br>
	 * Original signature : <code>LLVMModuleRef LLVMModuleCreateWithNameInContext(const char*, LLVMContextRef)</code>
	 */
	LLVMModuleRef LLVMModuleCreateWithNameInContext(const char* ModuleID, LLVMContextRef C);
	/**
	 * Destroy a module instance.<br>
	 * * This must be called for every created module or memory will be<br>
	 * leaked.<br>
	 * Original signature : <code>void LLVMDisposeModule(LLVMModuleRef)</code>
	 */
	void LLVMDisposeModule(LLVMModuleRef M);
	/**
	 * Obtain the data layout for a module.<br>
	 * * @see Module::getDataLayout()<br>
	 * Original signature : <code>char* LLVMGetDataLayout(LLVMModuleRef)</code>
	 */
	const char* LLVMGetDataLayout(LLVMModuleRef M);
	/**
	 * Set the data layout for a module.<br>
	 * * @see Module::setDataLayout()<br>
	 * Original signature : <code>void LLVMSetDataLayout(LLVMModuleRef, const char*)</code>
	 */
	void LLVMSetDataLayout(LLVMModuleRef M, const char* Triple);
	/**
	 * Obtain the target triple for a module.<br>
	 * * @see Module::getTargetTriple()<br>
	 * Original signature : <code>char* LLVMGetTarget(LLVMModuleRef)</code>
	 */
	const char* LLVMGetTarget(LLVMModuleRef M);
	/**
	 * Set the target triple for a module.<br>
	 * * @see Module::setTargetTriple()<br>
	 * Original signature : <code>void LLVMSetTarget(LLVMModuleRef, const char*)</code>
	 */
	void LLVMSetTarget(LLVMModuleRef M, const char* Triple);
	/**
	 * Dump a representation of a module to stderr.<br>
	 * * @see Module::dump()<br>
	 * Original signature : <code>void LLVMDumpModule(LLVMModuleRef)</code>
	 */
	void LLVMDumpModule(LLVMModuleRef M);
	/**
	 * Print a representation of a module to a file. The ErrorMessage needs to be<br>
	 * disposed with LLVMDisposeMessage. Returns 0 on success, 1 otherwise.<br>
	 * * @see Module::print()<br>
	 * Original signature : <code>LLVMBool LLVMPrintModuleToFile(LLVMModuleRef, const char*, char**)</code>
	 */
	LLVMBool LLVMPrintModuleToFile(LLVMModuleRef M, const char* Filename, char** ErrorMessage);
	/**
	 * Set inline assembly for a module.<br>
	 * * @see Module::setModuleInlineAsm()<br>
	 * Original signature : <code>void LLVMSetModuleInlineAsm(LLVMModuleRef, const char*)</code>
	 */
	void LLVMSetModuleInlineAsm(LLVMModuleRef M, const char* Asm);
	/**
	 * Obtain the context to which this module is associated.<br>
	 * * @see Module::getContext()<br>
	 * Original signature : <code>LLVMContextRef LLVMGetModuleContext(LLVMModuleRef)</code>
	 */
	LLVMContextRef LLVMGetModuleContext(LLVMModuleRef M);
	/**
	 * Obtain a Type from a module by its registered name.<br>
	 * Original signature : <code>LLVMTypeRef LLVMGetTypeByName(LLVMModuleRef, const char*)</code>
	 */
	LLVMTypeRef LLVMGetTypeByName(LLVMModuleRef M, const char* Name);
	/**
	 * Obtain the number of operands for named metadata in a module.<br>
	 * * @see llvm::Module::getNamedMetadata()<br>
	 * Original signature : <code>int LLVMGetNamedMetadataNumOperands(LLVMModuleRef, const char*)</code>
	 */
	unsigned int LLVMGetNamedMetadataNumOperands(LLVMModuleRef M, const char* name);
	/**
	 * Obtain the named metadata operands for a module.<br>
	 * * The passed LLVMValueRef pointer should refer to an array of<br>
	 * LLVMValueRef at least LLVMGetNamedMetadataNumOperands long. This<br>
	 * array will be populated with the LLVMValueRef instances. Each<br>
	 * instance corresponds to a llvm::MDNode.<br>
	 * * @see llvm::Module::getNamedMetadata()<br>
	 * @see llvm::MDNode::getOperand()<br>
	 * Original signature : <code>void LLVMGetNamedMetadataOperands(LLVMModuleRef, const char*, LLVMValueRef*)</code>
	 */
	void LLVMGetNamedMetadataOperands(LLVMModuleRef M, const char* name, LLVMValueRef* Dest);
	/**
	 * Add an operand to named metadata.<br>
	 * * @see llvm::Module::getNamedMetadata()<br>
	 * @see llvm::MDNode::addOperand()<br>
	 * Original signature : <code>void LLVMAddNamedMetadataOperand(LLVMModuleRef, const char*, LLVMValueRef)</code>
	 */
	void LLVMAddNamedMetadataOperand(LLVMModuleRef M, const char* name, LLVMValueRef Val);
	/**
	 * Add a function to a module under a specified name.<br>
	 * * @see llvm::Function::Create()<br>
	 * Original signature : <code>LLVMValueRef LLVMAddFunction(LLVMModuleRef, const char*, LLVMTypeRef)</code>
	 */
	LLVMValueRef LLVMAddFunction(LLVMModuleRef M, const char* Name, LLVMTypeRef FunctionTy);
	/**
	 * Obtain a Function value from a Module by its name.<br>
	 * * The returned value corresponds to a llvm::Function value.<br>
	 * * @see llvm::Module::getFunction()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetNamedFunction(LLVMModuleRef, const char*)</code>
	 */
	LLVMValueRef LLVMGetNamedFunction(LLVMModuleRef M, const char* Name);
	/**
	 * Obtain an iterator to the first Function in a Module.<br>
	 * * @see llvm::Module::begin()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetFirstFunction(LLVMModuleRef)</code>
	 */
	LLVMValueRef LLVMGetFirstFunction(LLVMModuleRef M);
	/**
	 * Obtain an iterator to the last Function in a Module.<br>
	 * * @see llvm::Module::end()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetLastFunction(LLVMModuleRef)</code>
	 */
	LLVMValueRef LLVMGetLastFunction(LLVMModuleRef M);
	/**
	 * Advance a Function iterator to the next Function.<br>
	 * * Returns NULL if the iterator was already at the end and there are no more<br>
	 * functions.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetNextFunction(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetNextFunction(LLVMValueRef Fn);
	/**
	 * Decrement a Function iterator to the previous Function.<br>
	 * * Returns NULL if the iterator was already at the beginning and there are<br>
	 * no previous functions.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetPreviousFunction(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetPreviousFunction(LLVMValueRef Fn);
	/**
	 * Obtain the enumerated type of a Type instance.<br>
	 * * @see llvm::Type:getTypeID()<br>
	 * Original signature : <code>LLVMTypeKind LLVMGetTypeKind(LLVMTypeRef)</code>
	 */
	LLVMTypeKind LLVMGetTypeKind(LLVMTypeRef Ty);
	/**
	 * Whether the type has a known size.<br>
	 * * Things that don't have a size are abstract types, labels, and void.a<br>
	 * * @see llvm::Type::isSized()<br>
	 * Original signature : <code>LLVMBool LLVMTypeIsSized(LLVMTypeRef)</code>
	 */
	LLVMBool LLVMTypeIsSized(LLVMTypeRef Ty);
	/**
	 * Obtain the context to which this type instance is associated.<br>
	 * * @see llvm::Type::getContext()<br>
	 * Original signature : <code>LLVMContextRef LLVMGetTypeContext(LLVMTypeRef)</code>
	 */
	LLVMContextRef LLVMGetTypeContext(LLVMTypeRef Ty);
	/**
	 * Obtain an integer type from a context with specified bit width.<br>
	 * Original signature : <code>LLVMTypeRef LLVMInt1TypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMInt1TypeInContext(LLVMContextRef C);
	/// Original signature : <code>LLVMTypeRef LLVMInt8TypeInContext(LLVMContextRef)</code>
	LLVMTypeRef LLVMInt8TypeInContext(LLVMContextRef C);
	/// Original signature : <code>LLVMTypeRef LLVMInt16TypeInContext(LLVMContextRef)</code>
	LLVMTypeRef LLVMInt16TypeInContext(LLVMContextRef C);
	/// Original signature : <code>LLVMTypeRef LLVMInt32TypeInContext(LLVMContextRef)</code>
	LLVMTypeRef LLVMInt32TypeInContext(LLVMContextRef C);
	/// Original signature : <code>LLVMTypeRef LLVMInt64TypeInContext(LLVMContextRef)</code>
	LLVMTypeRef LLVMInt64TypeInContext(LLVMContextRef C);
	/// Original signature : <code>LLVMTypeRef LLVMIntTypeInContext(LLVMContextRef, unsigned)</code>
	LLVMTypeRef LLVMIntTypeInContext(LLVMContextRef C, unsigned NumBits);
	/**
	 * Obtain an integer type from the global context with a specified bit<br>
	 * width.<br>
	 * Original signature : <code>LLVMTypeRef LLVMInt1Type()</code>
	 */
	LLVMTypeRef LLVMInt1Type();
	/// Original signature : <code>LLVMTypeRef LLVMInt8Type()</code>
	LLVMTypeRef LLVMInt8Type();
	/// Original signature : <code>LLVMTypeRef LLVMInt16Type()</code>
	LLVMTypeRef LLVMInt16Type();
	/// Original signature : <code>LLVMTypeRef LLVMInt32Type()</code>
	LLVMTypeRef LLVMInt32Type();
	/// Original signature : <code>LLVMTypeRef LLVMInt64Type()</code>
	LLVMTypeRef LLVMInt64Type();
	/// Original signature : <code>LLVMTypeRef LLVMIntType(unsigned)</code>
	LLVMTypeRef LLVMIntType(unsigned NumBits);
	/// Original signature : <code>int LLVMGetIntTypeWidth(LLVMTypeRef)</code>
	unsigned int LLVMGetIntTypeWidth(LLVMTypeRef IntegerTy);
	/**
	 * Obtain a 16-bit floating point type from a context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMHalfTypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMHalfTypeInContext(LLVMContextRef C);
	/**
	 * Obtain a 32-bit floating point type from a context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMFloatTypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMFloatTypeInContext(LLVMContextRef C);
	/**
	 * Obtain a 64-bit floating point type from a context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMDoubleTypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMDoubleTypeInContext(LLVMContextRef C);
	/**
	 * Obtain a 80-bit floating point type (X87) from a context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMX86FP80TypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMX86FP80TypeInContext(LLVMContextRef C);
	/**
	 * Obtain a 128-bit floating point type (112-bit mantissa) from a<br>
	 * context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMFP128TypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMFP128TypeInContext(LLVMContextRef C);
	/**
	 * Obtain a 128-bit floating point type (two 64-bits) from a context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMPPCFP128TypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMPPCFP128TypeInContext(LLVMContextRef C);
	/**
	 * Obtain a floating point type from the global context.<br>
	 * * These map to the functions in this group of the same name.<br>
	 * Original signature : <code>LLVMTypeRef LLVMHalfType()</code>
	 */
	LLVMTypeRef LLVMHalfType();
	/// Original signature : <code>LLVMTypeRef LLVMFloatType()</code>
	LLVMTypeRef LLVMFloatType();
	/// Original signature : <code>LLVMTypeRef LLVMDoubleType()</code>
	LLVMTypeRef LLVMDoubleType();
	/// Original signature : <code>LLVMTypeRef LLVMX86FP80Type()</code>
	LLVMTypeRef LLVMX86FP80Type();
	/// Original signature : <code>LLVMTypeRef LLVMFP128Type()</code>
	LLVMTypeRef LLVMFP128Type();
	/// Original signature : <code>LLVMTypeRef LLVMPPCFP128Type()</code>
	LLVMTypeRef LLVMPPCFP128Type();
	/**
	 * Obtain a function type consisting of a specified signature.<br>
	 * * The function is defined as a tuple of a return Type, a list of<br>
	 * parameter types, and whether the function is variadic.<br>
	 * Original signature : <code>LLVMTypeRef LLVMFunctionType(LLVMTypeRef, LLVMTypeRef*, unsigned, LLVMBool)</code>
	 */
	LLVMTypeRef LLVMFunctionType(LLVMTypeRef ReturnType, LLVMTypeRef* ParamTypes, unsigned ParamCount, LLVMBool IsVarArg);
	/**
	 * Returns whether a function type is variadic.<br>
	 * Original signature : <code>LLVMBool LLVMIsFunctionVarArg(LLVMTypeRef)</code>
	 */
	LLVMBool LLVMIsFunctionVarArg(LLVMTypeRef FunctionTy);
	/**
	 * Obtain the Type this function Type returns.<br>
	 * Original signature : <code>LLVMTypeRef LLVMGetReturnType(LLVMTypeRef)</code>
	 */
	LLVMTypeRef LLVMGetReturnType(LLVMTypeRef FunctionTy);
	/**
	 * Obtain the number of parameters this function accepts.<br>
	 * Original signature : <code>int LLVMCountParamTypes(LLVMTypeRef)</code>
	 */
	unsigned int LLVMCountParamTypes(LLVMTypeRef FunctionTy);
	/**
	 * Obtain the types of a function's parameters.<br>
	 * * The Dest parameter should point to a pre-allocated array of<br>
	 * LLVMTypeRef at least LLVMCountParamTypes() large. On return, the<br>
	 * first LLVMCountParamTypes() entries in the array will be populated<br>
	 * with LLVMTypeRef instances.<br>
	 * * @param FunctionTy The function type to operate on.<br>
	 * @param Dest Memory address of an array to be filled with result.<br>
	 * Original signature : <code>void LLVMGetParamTypes(LLVMTypeRef, LLVMTypeRef*)</code>
	 */
	void LLVMGetParamTypes(LLVMTypeRef FunctionTy, LLVMTypeRef* Dest);
	/**
	 * Create a new structure type in a context.<br>
	 * * A structure is specified by a list of inner elements/types and<br>
	 * whether these can be packed together.<br>
	 * * @see llvm::StructType::create()<br>
	 * Original signature : <code>LLVMTypeRef LLVMStructTypeInContext(LLVMContextRef, LLVMTypeRef*, unsigned, LLVMBool)</code>
	 */
	LLVMTypeRef LLVMStructTypeInContext(LLVMContextRef C, LLVMTypeRef* ElementTypes, unsigned ElementCount, LLVMBool Packed);
	/**
	 * Create a new structure type in the global context.<br>
	 * * @see llvm::StructType::create()<br>
	 * Original signature : <code>LLVMTypeRef LLVMStructType(LLVMTypeRef*, unsigned, LLVMBool)</code>
	 */
	LLVMTypeRef LLVMStructType(LLVMTypeRef* ElementTypes, unsigned ElementCount, LLVMBool Packed);
	/**
	 * Create an empty structure in a context having a specified name.<br>
	 * * @see llvm::StructType::create()<br>
	 * Original signature : <code>LLVMTypeRef LLVMStructCreateNamed(LLVMContextRef, const char*)</code>
	 */
	LLVMTypeRef LLVMStructCreateNamed(LLVMContextRef C, const char* Name);
	/**
	 * Obtain the name of a structure.<br>
	 * * @see llvm::StructType::getName()<br>
	 * Original signature : <code>char* LLVMGetStructName(LLVMTypeRef)</code>
	 */
	const char* LLVMGetStructName(LLVMTypeRef Ty);
	/**
	 * Set the contents of a structure type.<br>
	 * * @see llvm::StructType::setBody()<br>
	 * Original signature : <code>void LLVMStructSetBody(LLVMTypeRef, LLVMTypeRef*, unsigned, LLVMBool)</code>
	 */
	void LLVMStructSetBody(LLVMTypeRef StructTy, LLVMTypeRef* ElementTypes, unsigned ElementCount, LLVMBool Packed);
	/**
	 * Get the number of elements defined inside the structure.<br>
	 * * @see llvm::StructType::getNumElements()<br>
	 * Original signature : <code>int LLVMCountStructElementTypes(LLVMTypeRef)</code>
	 */
	unsigned int LLVMCountStructElementTypes(LLVMTypeRef StructTy);
	/**
	 * Get the elements within a structure.<br>
	 * * The function is passed the address of a pre-allocated array of<br>
	 * LLVMTypeRef at least LLVMCountStructElementTypes() long. After<br>
	 * invocation, this array will be populated with the structure's<br>
	 * elements. The objects in the destination array will have a lifetime<br>
	 * of the structure type itself, which is the lifetime of the context it<br>
	 * is contained in.<br>
	 * Original signature : <code>void LLVMGetStructElementTypes(LLVMTypeRef, LLVMTypeRef*)</code>
	 */
	void LLVMGetStructElementTypes(LLVMTypeRef StructTy, LLVMTypeRef* Dest);
	/**
	 * Determine whether a structure is packed.<br>
	 * * @see llvm::StructType::isPacked()<br>
	 * Original signature : <code>LLVMBool LLVMIsPackedStruct(LLVMTypeRef)</code>
	 */
	LLVMBool LLVMIsPackedStruct(LLVMTypeRef StructTy);
	/**
	 * Determine whether a structure is opaque.<br>
	 * * @see llvm::StructType::isOpaque()<br>
	 * Original signature : <code>LLVMBool LLVMIsOpaqueStruct(LLVMTypeRef)</code>
	 */
	LLVMBool LLVMIsOpaqueStruct(LLVMTypeRef StructTy);
	/**
	 * Obtain the type of elements within a sequential type.<br>
	 * * This works on array, vector, and pointer types.<br>
	 * * @see llvm::SequentialType::getElementType()<br>
	 * Original signature : <code>LLVMTypeRef LLVMGetElementType(LLVMTypeRef)</code>
	 */
	LLVMTypeRef LLVMGetElementType(LLVMTypeRef Ty);
	/**
	 * Create a fixed size array type that refers to a specific type.<br>
	 * * The created type will exist in the context that its element type<br>
	 * exists in.<br>
	 * * @see llvm::ArrayType::get()<br>
	 * Original signature : <code>LLVMTypeRef LLVMArrayType(LLVMTypeRef, unsigned)</code>
	 */
	LLVMTypeRef LLVMArrayType(LLVMTypeRef ElementType, unsigned ElementCount);
	/**
	 * Obtain the length of an array type.<br>
	 * * This only works on types that represent arrays.<br>
	 * * @see llvm::ArrayType::getNumElements()<br>
	 * Original signature : <code>int LLVMGetArrayLength(LLVMTypeRef)</code>
	 */
	unsigned int LLVMGetArrayLength(LLVMTypeRef ArrayTy);
	/**
	 * Create a pointer type that points to a defined type.<br>
	 * * The created type will exist in the context that its pointee type<br>
	 * exists in.<br>
	 * * @see llvm::PointerType::get()<br>
	 * Original signature : <code>LLVMTypeRef LLVMPointerType(LLVMTypeRef, unsigned)</code>
	 */
	LLVMTypeRef LLVMPointerType(LLVMTypeRef ElementType, unsigned AddressSpace);
	/**
	 * Obtain the address space of a pointer type.<br>
	 * * This only works on types that represent pointers.<br>
	 * * @see llvm::PointerType::getAddressSpace()<br>
	 * Original signature : <code>int LLVMGetPointerAddressSpace(LLVMTypeRef)</code>
	 */
	unsigned int LLVMGetPointerAddressSpace(LLVMTypeRef PointerTy);
	/**
	 * Create a vector type that contains a defined type and has a specific<br>
	 * number of elements.<br>
	 * * The created type will exist in the context thats its element type<br>
	 * exists in.<br>
	 * * @see llvm::VectorType::get()<br>
	 * Original signature : <code>LLVMTypeRef LLVMVectorType(LLVMTypeRef, unsigned)</code>
	 */
	LLVMTypeRef LLVMVectorType(LLVMTypeRef ElementType, unsigned ElementCount);
	/**
	 * Obtain the number of elements in a vector type.<br>
	 * * This only works on types that represent vectors.<br>
	 * * @see llvm::VectorType::getNumElements()<br>
	 * Original signature : <code>int LLVMGetVectorSize(LLVMTypeRef)</code>
	 */
	unsigned int LLVMGetVectorSize(LLVMTypeRef VectorTy);
	/**
	 * Create a void type in a context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMVoidTypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMVoidTypeInContext(LLVMContextRef C);
	/**
	 * Create a label type in a context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMLabelTypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMLabelTypeInContext(LLVMContextRef C);
	/**
	 * Create a X86 MMX type in a context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMX86MMXTypeInContext(LLVMContextRef)</code>
	 */
	LLVMTypeRef LLVMX86MMXTypeInContext(LLVMContextRef C);
	/**
	 * These are similar to the above functions except they operate on the<br>
	 * global context.<br>
	 * Original signature : <code>LLVMTypeRef LLVMVoidType()</code>
	 */
	LLVMTypeRef LLVMVoidType();
	/// Original signature : <code>LLVMTypeRef LLVMLabelType()</code>
	LLVMTypeRef LLVMLabelType();
	/// Original signature : <code>LLVMTypeRef LLVMX86MMXType()</code>
	LLVMTypeRef LLVMX86MMXType();
	/**
	 * Obtain the type of a value.<br>
	 * * @see llvm::Value::getType()<br>
	 * Original signature : <code>LLVMTypeRef LLVMTypeOf(LLVMValueRef)</code>
	 */
	LLVMTypeRef LLVMTypeOf(LLVMValueRef Val);
	/**
	 * Obtain the string name of a value.<br>
	 * * @see llvm::Value::getName()<br>
	 * Original signature : <code>char* LLVMGetValueName(LLVMValueRef)</code>
	 */
	const char* LLVMGetValueName(LLVMValueRef Val);
	/**
	 * Set the string name of a value.<br>
	 * * @see llvm::Value::setName()<br>
	 * Original signature : <code>void LLVMSetValueName(LLVMValueRef, const char*)</code>
	 */
	void LLVMSetValueName(LLVMValueRef Val, const char* Name);
	/**
	 * Dump a representation of a value to stderr.<br>
	 * * @see llvm::Value::dump()<br>
	 * Original signature : <code>void LLVMDumpValue(LLVMValueRef)</code>
	 */
	void LLVMDumpValue(LLVMValueRef Val);
	/**
	 * Replace all uses of a value with another one.<br>
	 * * @see llvm::Value::replaceAllUsesWith()<br>
	 * Original signature : <code>void LLVMReplaceAllUsesWith(LLVMValueRef, LLVMValueRef)</code>
	 */
	void LLVMReplaceAllUsesWith(LLVMValueRef OldVal, LLVMValueRef NewVal);
	/**
	 * Determine whether the specified constant instance is constant.<br>
	 * Original signature : <code>LLVMBool LLVMIsConstant(LLVMValueRef)</code>
	 */
	LLVMBool LLVMIsConstant(LLVMValueRef Val);
	/**
	 * Determine whether a value instance is undefined.<br>
	 * Original signature : <code>LLVMBool LLVMIsUndef(LLVMValueRef)</code>
	 */
	LLVMBool LLVMIsUndef(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAArgument(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAArgument(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsABasicBlock(LLVMValueRef)</code>
	LLVMValueRef LLVMIsABasicBlock(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAInlineAsm(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAInlineAsm(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAMDNode(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAMDNode(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAMDString(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAMDString(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAUser(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAUser(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstant(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstant(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsABlockAddress(LLVMValueRef)</code>
	LLVMValueRef LLVMIsABlockAddress(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstantAggregateZero(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstantAggregateZero(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstantArray(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstantArray(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstantExpr(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstantExpr(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstantFP(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstantFP(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstantInt(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstantInt(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstantPointerNull(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstantPointerNull(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstantStruct(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstantStruct(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAConstantVector(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAConstantVector(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAGlobalValue(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAGlobalValue(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAFunction(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAFunction(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAGlobalAlias(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAGlobalAlias(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAGlobalVariable(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAGlobalVariable(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAUndefValue(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAUndefValue(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAInstruction(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAInstruction(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsABinaryOperator(LLVMValueRef)</code>
	LLVMValueRef LLVMIsABinaryOperator(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsACallInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsACallInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAIntrinsicInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAIntrinsicInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsADbgInfoIntrinsic(LLVMValueRef)</code>
	LLVMValueRef LLVMIsADbgInfoIntrinsic(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsADbgDeclareInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsADbgDeclareInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAMemIntrinsic(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAMemIntrinsic(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAMemCpyInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAMemCpyInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAMemMoveInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAMemMoveInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAMemSetInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAMemSetInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsACmpInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsACmpInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAFCmpInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAFCmpInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAICmpInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAICmpInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAExtractElementInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAExtractElementInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAGetElementPtrInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAGetElementPtrInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAInsertElementInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAInsertElementInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAInsertValueInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAInsertValueInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsALandingPadInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsALandingPadInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAPHINode(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAPHINode(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsASelectInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsASelectInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAShuffleVectorInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAShuffleVectorInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAStoreInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAStoreInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsATerminatorInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsATerminatorInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsABranchInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsABranchInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAIndirectBrInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAIndirectBrInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAInvokeInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAInvokeInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAReturnInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAReturnInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsASwitchInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsASwitchInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAUnreachableInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAUnreachableInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAResumeInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAResumeInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAUnaryInstruction(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAUnaryInstruction(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAAllocaInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAAllocaInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsACastInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsACastInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsABitCastInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsABitCastInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAFPExtInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAFPExtInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAFPToSIInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAFPToSIInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAFPToUIInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAFPToUIInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAFPTruncInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAFPTruncInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAIntToPtrInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAIntToPtrInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAPtrToIntInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAPtrToIntInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsASExtInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsASExtInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsASIToFPInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsASIToFPInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsATruncInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsATruncInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAUIToFPInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAUIToFPInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAZExtInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAZExtInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAExtractValueInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAExtractValueInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsALoadInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsALoadInst(LLVMValueRef Val);
	/// Original signature : <code>LLVMValueRef LLVMIsAVAArgInst(LLVMValueRef)</code>
	LLVMValueRef LLVMIsAVAArgInst(LLVMValueRef Val);
	/**
	 * Obtain the first use of a value.<br>
	 * * Uses are obtained in an iterator fashion. First, call this function<br>
	 * to obtain a reference to the first use. Then, call LLVMGetNextUse()<br>
	 * on that instance and all subsequently obtained instances until<br>
	 * LLVMGetNextUse() returns NULL.<br>
	 * * @see llvm::Value::use_begin()<br>
	 * Original signature : <code>LLVMUseRef LLVMGetFirstUse(LLVMValueRef)</code>
	 */
	LLVMUseRef LLVMGetFirstUse(LLVMValueRef Val);
	/**
	 * Obtain the next use of a value.<br>
	 * * This effectively advances the iterator. It returns NULL if you are on<br>
	 * the final use and no more are available.<br>
	 * Original signature : <code>LLVMUseRef LLVMGetNextUse(LLVMUseRef)</code>
	 */
	LLVMUseRef LLVMGetNextUse(LLVMUseRef U);
	/**
	 * Obtain the user value for a user.<br>
	 * * The returned value corresponds to a llvm::User type.<br>
	 * * @see llvm::Use::getUser()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetUser(LLVMUseRef)</code>
	 */
	LLVMValueRef LLVMGetUser(LLVMUseRef U);
	/**
	 * Obtain the value this use corresponds to.<br>
	 * * @see llvm::Use::get().<br>
	 * Original signature : <code>LLVMValueRef LLVMGetUsedValue(LLVMUseRef)</code>
	 */
	LLVMValueRef LLVMGetUsedValue(LLVMUseRef U);
	/**
	 * Obtain an operand at a specific index in a llvm::User value.<br>
	 * * @see llvm::User::getOperand()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetOperand(LLVMValueRef, unsigned)</code>
	 */
	LLVMValueRef LLVMGetOperand(LLVMValueRef Val, unsigned Index);
	/**
	 * Set an operand at a specific index in a llvm::User value.<br>
	 * * @see llvm::User::setOperand()<br>
	 * Original signature : <code>void LLVMSetOperand(LLVMValueRef, unsigned, LLVMValueRef)</code>
	 */
	void LLVMSetOperand(LLVMValueRef User, unsigned Index, LLVMValueRef Val);
	/**
	 * Obtain the number of operands in a llvm::User value.<br>
	 * * @see llvm::User::getNumOperands()<br>
	 * Original signature : <code>int LLVMGetNumOperands(LLVMValueRef)</code>
	 */
	int LLVMGetNumOperands(LLVMValueRef Val);
	/**
	 * Obtain a constant value referring to the null instance of a type.<br>
	 * * @see llvm::Constant::getNullValue()<br>
	 * all zeroes<br>
	 * Original signature : <code>LLVMValueRef LLVMConstNull(LLVMTypeRef)</code>
	 */
	LLVMValueRef LLVMConstNull(LLVMTypeRef Ty);
	/**
	 * Obtain a constant value referring to the instance of a type<br>
	 * consisting of all ones.<br>
	 * * This is only valid for integer types.<br>
	 * * @see llvm::Constant::getAllOnesValue()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstAllOnes(LLVMTypeRef)</code>
	 */
	LLVMValueRef LLVMConstAllOnes(LLVMTypeRef Ty);
	/**
	 * Obtain a constant value referring to an undefined value of a type.<br>
	 * * @see llvm::UndefValue::get()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetUndef(LLVMTypeRef)</code>
	 */
	LLVMValueRef LLVMGetUndef(LLVMTypeRef Ty);
	/**
	 * Determine whether a value instance is null.<br>
	 * * @see llvm::Constant::isNullValue()<br>
	 * Original signature : <code>LLVMBool LLVMIsNull(LLVMValueRef)</code>
	 */
	LLVMBool LLVMIsNull(LLVMValueRef Val);
	/**
	 * Obtain a constant that is a constant pointer pointing to NULL for a<br>
	 * specified type.<br>
	 * Original signature : <code>LLVMValueRef LLVMConstPointerNull(LLVMTypeRef)</code>
	 */
	LLVMValueRef LLVMConstPointerNull(LLVMTypeRef Ty);
	/**
	 * Obtain a constant value for an integer type.<br>
	 * * The returned value corresponds to a llvm::ConstantInt.<br>
	 * * @see llvm::ConstantInt::get()<br>
	 * * @param IntTy Integer type to obtain value of.<br>
	 * @param N The value the returned instance should refer to.<br>
	 * @param SignExtend Whether to sign extend the produced value.<br>
	 * Original signature : <code>LLVMValueRef LLVMConstInt(LLVMTypeRef, unsigned long long, LLVMBool)</code>
	 */
	LLVMValueRef LLVMConstInt(LLVMTypeRef IntTy, unsigned long long N, LLVMBool SignExtend);
	/**
	 * Obtain a constant value for an integer of arbitrary precision.<br>
	 * * @see llvm::ConstantInt::get()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstIntOfArbitraryPrecision(LLVMTypeRef, unsigned, const uint64_t[])</code>
	 */
	LLVMValueRef LLVMConstIntOfArbitraryPrecision(LLVMTypeRef IntTy, unsigned NumWords, const uint64_t Words[]);
	/**
	 * Obtain a constant value for an integer parsed from a string.<br>
	 * * A similar API, LLVMConstIntOfStringAndSize is also available. If the<br>
	 * string's length is available, it is preferred to call that function<br>
	 * instead.<br>
	 * * @see llvm::ConstantInt::get()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstIntOfString(LLVMTypeRef, const char*, uint8_t)</code>
	 */
	LLVMValueRef LLVMConstIntOfString(LLVMTypeRef IntTy, const char* Text, uint8_t Radix);
	/**
	 * Obtain a constant value for an integer parsed from a string with<br>
	 * specified length.<br>
	 * * @see llvm::ConstantInt::get()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstIntOfStringAndSize(LLVMTypeRef, const char*, unsigned, uint8_t)</code>
	 */
	LLVMValueRef LLVMConstIntOfStringAndSize(LLVMTypeRef IntTy, const char* Text, unsigned SLen, uint8_t Radix);
	/**
	 * Obtain a constant value referring to a double floating point value.<br>
	 * Original signature : <code>LLVMValueRef LLVMConstReal(LLVMTypeRef, double)</code>
	 */
	LLVMValueRef LLVMConstReal(LLVMTypeRef RealTy, double N);
	/**
	 * Obtain a constant for a floating point value parsed from a string.<br>
	 * * A similar API, LLVMConstRealOfStringAndSize is also available. It<br>
	 * should be used if the input string's length is known.<br>
	 * Original signature : <code>LLVMValueRef LLVMConstRealOfString(LLVMTypeRef, const char*)</code>
	 */
	LLVMValueRef LLVMConstRealOfString(LLVMTypeRef RealTy, const char* Text);
	/**
	 * Obtain a constant for a floating point value parsed from a string.<br>
	 * Original signature : <code>LLVMValueRef LLVMConstRealOfStringAndSize(LLVMTypeRef, const char*, unsigned)</code>
	 */
	LLVMValueRef LLVMConstRealOfStringAndSize(LLVMTypeRef RealTy, const char* Text, unsigned SLen);
	/**
	 * Obtain the zero extended value for an integer constant value.<br>
	 * * @see llvm::ConstantInt::getZExtValue()<br>
	 * Original signature : <code>long long LLVMConstIntGetZExtValue(LLVMValueRef)</code>
	 */
	unsigned long long LLVMConstIntGetZExtValue(LLVMValueRef ConstantVal);
	/**
	 * Obtain the sign extended value for an integer constant value.<br>
	 * * @see llvm::ConstantInt::getSExtValue()<br>
	 * Original signature : <code>long long LLVMConstIntGetSExtValue(LLVMValueRef)</code>
	 */
	long long LLVMConstIntGetSExtValue(LLVMValueRef ConstantVal);
	/**
	 * Create a ConstantDataSequential and initialize it with a string.<br>
	 * * @see llvm::ConstantDataArray::getString()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstStringInContext(LLVMContextRef, const char*, unsigned, LLVMBool)</code>
	 */
	LLVMValueRef LLVMConstStringInContext(LLVMContextRef C, const char* Str, unsigned Length, LLVMBool DontNullTerminate);
	/**
	 * Create a ConstantDataSequential with string content in the global context.<br>
	 * * This is the same as LLVMConstStringInContext except it operates on the<br>
	 * global context.<br>
	 * * @see LLVMConstStringInContext()<br>
	 * @see llvm::ConstantDataArray::getString()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstString(const char*, unsigned, LLVMBool)</code>
	 */
	LLVMValueRef LLVMConstString(const char* Str, unsigned Length, LLVMBool DontNullTerminate);
	/**
	 * Create an anonymous ConstantStruct with the specified values.<br>
	 * * @see llvm::ConstantStruct::getAnon()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstStructInContext(LLVMContextRef, LLVMValueRef*, unsigned, LLVMBool)</code>
	 */
	LLVMValueRef LLVMConstStructInContext(LLVMContextRef C, LLVMValueRef* ConstantVals, unsigned Count, LLVMBool Packed);
	/**
	 * Create a ConstantStruct in the global Context.<br>
	 * * This is the same as LLVMConstStructInContext except it operates on the<br>
	 * global Context.<br>
	 * * @see LLVMConstStructInContext()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstStruct(LLVMValueRef*, unsigned, LLVMBool)</code>
	 */
	LLVMValueRef LLVMConstStruct(LLVMValueRef* ConstantVals, unsigned Count, LLVMBool Packed);
	/**
	 * Create a ConstantArray from values.<br>
	 * * @see llvm::ConstantArray::get()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstArray(LLVMTypeRef, LLVMValueRef*, unsigned)</code>
	 */
	LLVMValueRef LLVMConstArray(LLVMTypeRef ElementTy, LLVMValueRef* ConstantVals, unsigned Length);
	/**
	 * Create a non-anonymous ConstantStruct from values.<br>
	 * * @see llvm::ConstantStruct::get()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstNamedStruct(LLVMTypeRef, LLVMValueRef*, unsigned)</code>
	 */
	LLVMValueRef LLVMConstNamedStruct(LLVMTypeRef StructTy, LLVMValueRef* ConstantVals, unsigned Count);
	/**
	 * Create a ConstantVector from values.<br>
	 * * @see llvm::ConstantVector::get()<br>
	 * Original signature : <code>LLVMValueRef LLVMConstVector(LLVMValueRef*, unsigned)</code>
	 */
	LLVMValueRef LLVMConstVector(LLVMValueRef* ScalarConstantVals, unsigned Size);
	/**
	 * @defgroup LLVMCCoreValueConstantExpressions Constant Expressions<br>
	 * * Functions in this group correspond to APIs on llvm::ConstantExpr.<br>
	 * * @see llvm::ConstantExpr.<br>
	 * * @{<br>
	 * Original signature : <code>LLVMOpcode LLVMGetConstOpcode(LLVMValueRef)</code>
	 */
	LLVMOpcode LLVMGetConstOpcode(LLVMValueRef ConstantVal);
	/// Original signature : <code>LLVMValueRef LLVMAlignOf(LLVMTypeRef)</code>
	LLVMValueRef LLVMAlignOf(LLVMTypeRef Ty);
	/// Original signature : <code>LLVMValueRef LLVMSizeOf(LLVMTypeRef)</code>
	LLVMValueRef LLVMSizeOf(LLVMTypeRef Ty);
	/// Original signature : <code>LLVMValueRef LLVMConstNeg(LLVMValueRef)</code>
	LLVMValueRef LLVMConstNeg(LLVMValueRef ConstantVal);
	/// Original signature : <code>LLVMValueRef LLVMConstNSWNeg(LLVMValueRef)</code>
	LLVMValueRef LLVMConstNSWNeg(LLVMValueRef ConstantVal);
	/// Original signature : <code>LLVMValueRef LLVMConstNUWNeg(LLVMValueRef)</code>
	LLVMValueRef LLVMConstNUWNeg(LLVMValueRef ConstantVal);
	/// Original signature : <code>LLVMValueRef LLVMConstFNeg(LLVMValueRef)</code>
	LLVMValueRef LLVMConstFNeg(LLVMValueRef ConstantVal);
	/// Original signature : <code>LLVMValueRef LLVMConstNot(LLVMValueRef)</code>
	LLVMValueRef LLVMConstNot(LLVMValueRef ConstantVal);
	/// Original signature : <code>LLVMValueRef LLVMConstAdd(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstAdd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstNSWAdd(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstNSWAdd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstNUWAdd(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstNUWAdd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstFAdd(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstFAdd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstSub(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstSub(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstNSWSub(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstNSWSub(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstNUWSub(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstNUWSub(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstFSub(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstFSub(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstMul(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstMul(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstNSWMul(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstNSWMul(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstNUWMul(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstNUWMul(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstFMul(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstFMul(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstUDiv(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstUDiv(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstSDiv(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstSDiv(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstExactSDiv(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstExactSDiv(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstFDiv(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstFDiv(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstURem(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstURem(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstSRem(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstSRem(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstFRem(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstFRem(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstAnd(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstAnd(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstOr(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstOr(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstXor(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstXor(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstICmp(LLVMIntPredicate, LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstICmp(LLVMIntPredicate Predicate, LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstFCmp(LLVMRealPredicate, LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstFCmp(LLVMRealPredicate Predicate, LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstShl(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstShl(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstLShr(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstLShr(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstAShr(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstAShr(LLVMValueRef LHSConstant, LLVMValueRef RHSConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstGEP(LLVMValueRef, LLVMValueRef*, unsigned)</code>
	LLVMValueRef LLVMConstGEP(LLVMValueRef ConstantVal, LLVMValueRef* ConstantIndices, unsigned NumIndices);
	/// Original signature : <code>LLVMValueRef LLVMConstInBoundsGEP(LLVMValueRef, LLVMValueRef*, unsigned)</code>
	LLVMValueRef LLVMConstInBoundsGEP(LLVMValueRef ConstantVal, LLVMValueRef* ConstantIndices, unsigned NumIndices);
	/// Original signature : <code>LLVMValueRef LLVMConstTrunc(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstTrunc(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstSExt(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstSExt(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstZExt(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstZExt(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstFPTrunc(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstFPTrunc(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstFPExt(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstFPExt(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstUIToFP(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstUIToFP(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstSIToFP(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstSIToFP(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstFPToUI(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstFPToUI(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstFPToSI(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstFPToSI(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstPtrToInt(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstPtrToInt(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstIntToPtr(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstIntToPtr(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstBitCast(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstBitCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstZExtOrBitCast(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstZExtOrBitCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstSExtOrBitCast(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstSExtOrBitCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstTruncOrBitCast(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstTruncOrBitCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstPointerCast(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstPointerCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstIntCast(LLVMValueRef, LLVMTypeRef, LLVMBool)</code>
	LLVMValueRef LLVMConstIntCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType, LLVMBool isSigned);
	/// Original signature : <code>LLVMValueRef LLVMConstFPCast(LLVMValueRef, LLVMTypeRef)</code>
	LLVMValueRef LLVMConstFPCast(LLVMValueRef ConstantVal, LLVMTypeRef ToType);
	/// Original signature : <code>LLVMValueRef LLVMConstSelect(LLVMValueRef, LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstSelect(LLVMValueRef ConstantCondition, LLVMValueRef ConstantIfTrue, LLVMValueRef ConstantIfFalse);
	/// Original signature : <code>LLVMValueRef LLVMConstExtractElement(LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstExtractElement(LLVMValueRef VectorConstant, LLVMValueRef IndexConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstInsertElement(LLVMValueRef, LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstInsertElement(LLVMValueRef VectorConstant, LLVMValueRef ElementValueConstant, LLVMValueRef IndexConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstShuffleVector(LLVMValueRef, LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMConstShuffleVector(LLVMValueRef VectorAConstant, LLVMValueRef VectorBConstant, LLVMValueRef MaskConstant);
	/// Original signature : <code>LLVMValueRef LLVMConstExtractValue(LLVMValueRef, unsigned*, unsigned)</code>
	LLVMValueRef LLVMConstExtractValue(LLVMValueRef AggConstant, unsigned* IdxList, unsigned NumIdx);
	/// Original signature : <code>LLVMValueRef LLVMConstInsertValue(LLVMValueRef, LLVMValueRef, unsigned*, unsigned)</code>
	LLVMValueRef LLVMConstInsertValue(LLVMValueRef AggConstant, LLVMValueRef ElementValueConstant, unsigned* IdxList, unsigned NumIdx);
	/// Original signature : <code>LLVMValueRef LLVMConstInlineAsm(LLVMTypeRef, const char*, const char*, LLVMBool, LLVMBool)</code>
	LLVMValueRef LLVMConstInlineAsm(LLVMTypeRef Ty, const char* AsmString, const char* Constraints, LLVMBool HasSideEffects, LLVMBool IsAlignStack);
	/// Original signature : <code>LLVMValueRef LLVMBlockAddress(LLVMValueRef, LLVMBasicBlockRef)</code>
	LLVMValueRef LLVMBlockAddress(LLVMValueRef F, LLVMBasicBlockRef BB);
	/// Original signature : <code>LLVMModuleRef LLVMGetGlobalParent(LLVMValueRef)</code>
	LLVMModuleRef LLVMGetGlobalParent(LLVMValueRef Global);
	/// Original signature : <code>LLVMBool LLVMIsDeclaration(LLVMValueRef)</code>
	LLVMBool LLVMIsDeclaration(LLVMValueRef Global);
	/// Original signature : <code>LLVMLinkage LLVMGetLinkage(LLVMValueRef)</code>
	LLVMLinkage LLVMGetLinkage(LLVMValueRef Global);
	/// Original signature : <code>void LLVMSetLinkage(LLVMValueRef, LLVMLinkage)</code>
	void LLVMSetLinkage(LLVMValueRef Global, LLVMLinkage Linkage);
	/// Original signature : <code>char* LLVMGetSection(LLVMValueRef)</code>
	const char* LLVMGetSection(LLVMValueRef Global);
	/// Original signature : <code>void LLVMSetSection(LLVMValueRef, const char*)</code>
	void LLVMSetSection(LLVMValueRef Global, const char* Section);
	/// Original signature : <code>LLVMVisibility LLVMGetVisibility(LLVMValueRef)</code>
	LLVMVisibility LLVMGetVisibility(LLVMValueRef Global);
	/// Original signature : <code>void LLVMSetVisibility(LLVMValueRef, LLVMVisibility)</code>
	void LLVMSetVisibility(LLVMValueRef Global, LLVMVisibility Viz);
	/// Original signature : <code>int LLVMGetAlignment(LLVMValueRef)</code>
	unsigned int LLVMGetAlignment(LLVMValueRef Global);
	/// Original signature : <code>void LLVMSetAlignment(LLVMValueRef, unsigned)</code>
	void LLVMSetAlignment(LLVMValueRef Global, unsigned Bytes);
	/**
	 * @defgroup LLVMCoreValueConstantGlobalVariable Global Variables<br>
	 * * This group contains functions that operate on global variable values.<br>
	 * * @see llvm::GlobalVariable<br>
	 * * @{<br>
	 * Original signature : <code>LLVMValueRef LLVMAddGlobal(LLVMModuleRef, LLVMTypeRef, const char*)</code>
	 */
	LLVMValueRef LLVMAddGlobal(LLVMModuleRef M, LLVMTypeRef Ty, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMAddGlobalInAddressSpace(LLVMModuleRef, LLVMTypeRef, const char*, unsigned)</code>
	LLVMValueRef LLVMAddGlobalInAddressSpace(LLVMModuleRef M, LLVMTypeRef Ty, const char* Name, unsigned AddressSpace);
	/// Original signature : <code>LLVMValueRef LLVMGetNamedGlobal(LLVMModuleRef, const char*)</code>
	LLVMValueRef LLVMGetNamedGlobal(LLVMModuleRef M, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMGetFirstGlobal(LLVMModuleRef)</code>
	LLVMValueRef LLVMGetFirstGlobal(LLVMModuleRef M);
	/// Original signature : <code>LLVMValueRef LLVMGetLastGlobal(LLVMModuleRef)</code>
	LLVMValueRef LLVMGetLastGlobal(LLVMModuleRef M);
	/// Original signature : <code>LLVMValueRef LLVMGetNextGlobal(LLVMValueRef)</code>
	LLVMValueRef LLVMGetNextGlobal(LLVMValueRef GlobalVar);
	/// Original signature : <code>LLVMValueRef LLVMGetPreviousGlobal(LLVMValueRef)</code>
	LLVMValueRef LLVMGetPreviousGlobal(LLVMValueRef GlobalVar);
	/// Original signature : <code>void LLVMDeleteGlobal(LLVMValueRef)</code>
	void LLVMDeleteGlobal(LLVMValueRef GlobalVar);
	/// Original signature : <code>LLVMValueRef LLVMGetInitializer(LLVMValueRef)</code>
	LLVMValueRef LLVMGetInitializer(LLVMValueRef GlobalVar);
	/// Original signature : <code>void LLVMSetInitializer(LLVMValueRef, LLVMValueRef)</code>
	void LLVMSetInitializer(LLVMValueRef GlobalVar, LLVMValueRef ConstantVal);
	/// Original signature : <code>LLVMBool LLVMIsThreadLocal(LLVMValueRef)</code>
	LLVMBool LLVMIsThreadLocal(LLVMValueRef GlobalVar);
	/// Original signature : <code>void LLVMSetThreadLocal(LLVMValueRef, LLVMBool)</code>
	void LLVMSetThreadLocal(LLVMValueRef GlobalVar, LLVMBool IsThreadLocal);
	/// Original signature : <code>LLVMBool LLVMIsGlobalConstant(LLVMValueRef)</code>
	LLVMBool LLVMIsGlobalConstant(LLVMValueRef GlobalVar);
	/// Original signature : <code>void LLVMSetGlobalConstant(LLVMValueRef, LLVMBool)</code>
	void LLVMSetGlobalConstant(LLVMValueRef GlobalVar, LLVMBool IsConstant);
	/// Original signature : <code>LLVMThreadLocalMode LLVMGetThreadLocalMode(LLVMValueRef)</code>
	LLVMThreadLocalMode LLVMGetThreadLocalMode(LLVMValueRef GlobalVar);
	/// Original signature : <code>void LLVMSetThreadLocalMode(LLVMValueRef, LLVMThreadLocalMode)</code>
	void LLVMSetThreadLocalMode(LLVMValueRef GlobalVar, LLVMThreadLocalMode Mode);
	/// Original signature : <code>LLVMBool LLVMIsExternallyInitialized(LLVMValueRef)</code>
	LLVMBool LLVMIsExternallyInitialized(LLVMValueRef GlobalVar);
	/// Original signature : <code>void LLVMSetExternallyInitialized(LLVMValueRef, LLVMBool)</code>
	void LLVMSetExternallyInitialized(LLVMValueRef GlobalVar, LLVMBool IsExtInit);
	/**
	 * @defgroup LLVMCoreValueConstantGlobalAlias Global Aliases<br>
	 * * This group contains function that operate on global alias values.<br>
	 * * @see llvm::GlobalAlias<br>
	 * * @{<br>
	 * Original signature : <code>LLVMValueRef LLVMAddAlias(LLVMModuleRef, LLVMTypeRef, LLVMValueRef, const char*)</code>
	 */
	LLVMValueRef LLVMAddAlias(LLVMModuleRef M, LLVMTypeRef Ty, LLVMValueRef Aliasee, const char* Name);
	/**
	 * Remove a function from its containing module and deletes it.<br>
	 * * @see llvm::Function::eraseFromParent()<br>
	 * Original signature : <code>void LLVMDeleteFunction(LLVMValueRef)</code>
	 */
	void LLVMDeleteFunction(LLVMValueRef Fn);
	/**
	 * Obtain the ID number from a function instance.<br>
	 * * @see llvm::Function::getIntrinsicID()<br>
	 * Original signature : <code>int LLVMGetIntrinsicID(LLVMValueRef)</code>
	 */
	unsigned int LLVMGetIntrinsicID(LLVMValueRef Fn);
	/**
	 * Obtain the calling function of a function.<br>
	 * * The returned value corresponds to the LLVMCallConv enumeration.<br>
	 * * @see llvm::Function::getCallingConv()<br>
	 * Original signature : <code>int LLVMGetFunctionCallConv(LLVMValueRef)</code>
	 */
	unsigned int LLVMGetFunctionCallConv(LLVMValueRef Fn);
	/**
	 * Set the calling convention of a function.<br>
	 * * @see llvm::Function::setCallingConv()<br>
	 * * @param Fn Function to operate on<br>
	 * @param CC LLVMCallConv to set calling convention to<br>
	 * Original signature : <code>void LLVMSetFunctionCallConv(LLVMValueRef, unsigned)</code>
	 */
	void LLVMSetFunctionCallConv(LLVMValueRef Fn, unsigned CC);
	/**
	 * Obtain the name of the garbage collector to use during code<br>
	 * generation.<br>
	 * * @see llvm::Function::getGC()<br>
	 * Original signature : <code>char* LLVMGetGC(LLVMValueRef)</code>
	 */
	const char* LLVMGetGC(LLVMValueRef Fn);
	/**
	 * Define the garbage collector to use during code generation.<br>
	 * * @see llvm::Function::setGC()<br>
	 * Original signature : <code>void LLVMSetGC(LLVMValueRef, const char*)</code>
	 */
	void LLVMSetGC(LLVMValueRef Fn, const char* Name);
	/**
	 * Add an attribute to a function.<br>
	 * * @see llvm::Function::addAttribute()<br>
	 * Original signature : <code>void LLVMAddFunctionAttr(LLVMValueRef, LLVMAttribute)</code>
	 */
	void LLVMAddFunctionAttr(LLVMValueRef Fn, LLVMAttribute PA);
	/**
	 * Add a target-dependent attribute to a fuction<br>
	 * @see llvm::AttrBuilder::addAttribute()<br>
	 * Original signature : <code>void LLVMAddTargetDependentFunctionAttr(LLVMValueRef, const char*, const char*)</code>
	 */
	void LLVMAddTargetDependentFunctionAttr(LLVMValueRef Fn, const char* A, const char* V);
	/**
	 * Obtain an attribute from a function.<br>
	 * * @see llvm::Function::getAttributes()<br>
	 * Original signature : <code>LLVMAttribute LLVMGetFunctionAttr(LLVMValueRef)</code>
	 */
	LLVMAttribute LLVMGetFunctionAttr(LLVMValueRef Fn);
	/**
	 * Remove an attribute from a function.<br>
	 * Original signature : <code>void LLVMRemoveFunctionAttr(LLVMValueRef, LLVMAttribute)</code>
	 */
	void LLVMRemoveFunctionAttr(LLVMValueRef Fn, LLVMAttribute PA);
	/**
	 * Obtain the number of parameters in a function.<br>
	 * * @see llvm::Function::arg_size()<br>
	 * Original signature : <code>int LLVMCountParams(LLVMValueRef)</code>
	 */
	unsigned int LLVMCountParams(LLVMValueRef Fn);
	/**
	 * Obtain the parameters in a function.<br>
	 * * The takes a pointer to a pre-allocated array of LLVMValueRef that is<br>
	 * at least LLVMCountParams() long. This array will be filled with<br>
	 * LLVMValueRef instances which correspond to the parameters the<br>
	 * function receives. Each LLVMValueRef corresponds to a llvm::Argument<br>
	 * instance.<br>
	 * * @see llvm::Function::arg_begin()<br>
	 * Original signature : <code>void LLVMGetParams(LLVMValueRef, LLVMValueRef*)</code>
	 */
	void LLVMGetParams(LLVMValueRef Fn, LLVMValueRef* Params);
	/**
	 * Obtain the parameter at the specified index.<br>
	 * * Parameters are indexed from 0.<br>
	 * * @see llvm::Function::arg_begin()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetParam(LLVMValueRef, unsigned)</code>
	 */
	LLVMValueRef LLVMGetParam(LLVMValueRef Fn, unsigned Index);
	/**
	 * Obtain the function to which this argument belongs.<br>
	 * * Unlike other functions in this group, this one takes a LLVMValueRef<br>
	 * that corresponds to a llvm::Attribute.<br>
	 * * The returned LLVMValueRef is the llvm::Function to which this<br>
	 * argument belongs.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetParamParent(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetParamParent(LLVMValueRef Inst);
	/**
	 * Obtain the first parameter to a function.<br>
	 * * @see llvm::Function::arg_begin()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetFirstParam(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetFirstParam(LLVMValueRef Fn);
	/**
	 * Obtain the last parameter to a function.<br>
	 * * @see llvm::Function::arg_end()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetLastParam(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetLastParam(LLVMValueRef Fn);
	/**
	 * Obtain the next parameter to a function.<br>
	 * * This takes a LLVMValueRef obtained from LLVMGetFirstParam() (which is<br>
	 * actually a wrapped iterator) and obtains the next parameter from the<br>
	 * underlying iterator.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetNextParam(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetNextParam(LLVMValueRef Arg);
	/**
	 * Obtain the previous parameter to a function.<br>
	 * * This is the opposite of LLVMGetNextParam().<br>
	 * Original signature : <code>LLVMValueRef LLVMGetPreviousParam(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetPreviousParam(LLVMValueRef Arg);
	/**
	 * Add an attribute to a function argument.<br>
	 * * @see llvm::Argument::addAttr()<br>
	 * Original signature : <code>void LLVMAddAttribute(LLVMValueRef, LLVMAttribute)</code>
	 */
	void LLVMAddAttribute(LLVMValueRef Arg, LLVMAttribute PA);
	/**
	 * Remove an attribute from a function argument.<br>
	 * * @see llvm::Argument::removeAttr()<br>
	 * Original signature : <code>void LLVMRemoveAttribute(LLVMValueRef, LLVMAttribute)</code>
	 */
	void LLVMRemoveAttribute(LLVMValueRef Arg, LLVMAttribute PA);
	/**
	 * Get an attribute from a function argument.<br>
	 * Original signature : <code>LLVMAttribute LLVMGetAttribute(LLVMValueRef)</code>
	 */
	LLVMAttribute LLVMGetAttribute(LLVMValueRef Arg);
	/**
	 * Set the alignment for a function parameter.<br>
	 * * @see llvm::Argument::addAttr()<br>
	 * @see llvm::AttrBuilder::addAlignmentAttr()<br>
	 * Original signature : <code>void LLVMSetParamAlignment(LLVMValueRef, unsigned)</code>
	 */
	void LLVMSetParamAlignment(LLVMValueRef Arg, unsigned align);
	/**
	 * Obtain a MDString value from a context.<br>
	 * * The returned instance corresponds to the llvm::MDString class.<br>
	 * * The instance is specified by string data of a specified length. The<br>
	 * string content is copied, so the backing memory can be freed after<br>
	 * this function returns.<br>
	 * Original signature : <code>LLVMValueRef LLVMMDStringInContext(LLVMContextRef, const char*, unsigned)</code>
	 */
	LLVMValueRef LLVMMDStringInContext(LLVMContextRef C, const char* Str, unsigned SLen);
	/**
	 * Obtain a MDString value from the global context.<br>
	 * Original signature : <code>LLVMValueRef LLVMMDString(const char*, unsigned)</code>
	 */
	LLVMValueRef LLVMMDString(const char* Str, unsigned SLen);
	/**
	 * Obtain a MDNode value from a context.<br>
	 * * The returned value corresponds to the llvm::MDNode class.<br>
	 * Original signature : <code>LLVMValueRef LLVMMDNodeInContext(LLVMContextRef, LLVMValueRef*, unsigned)</code>
	 */
	LLVMValueRef LLVMMDNodeInContext(LLVMContextRef C, LLVMValueRef* Vals, unsigned Count);
	/**
	 * Obtain a MDNode value from the global context.<br>
	 * Original signature : <code>LLVMValueRef LLVMMDNode(LLVMValueRef*, unsigned)</code>
	 */
	LLVMValueRef LLVMMDNode(LLVMValueRef* Vals, unsigned Count);
	/**
	 * Obtain the underlying string from a MDString value.<br>
	 * * @param V Instance to obtain string from.<br>
	 * @param Len Memory address which will hold length of returned string.<br>
	 * @return String data in MDString.<br>
	 * Original signature : <code>char* LLVMGetMDString(LLVMValueRef, unsigned*)</code>
	 */
	const char* LLVMGetMDString(LLVMValueRef V, unsigned* Len);
	/**
	 * Obtain the number of operands from an MDNode value.<br>
	 * * @param V MDNode to get number of operands from.<br>
	 * @return Number of operands of the MDNode.<br>
	 * Original signature : <code>int LLVMGetMDNodeNumOperands(LLVMValueRef)</code>
	 */
	unsigned int LLVMGetMDNodeNumOperands(LLVMValueRef V);
	/**
	 * Obtain the given MDNode's operands.<br>
	 * * The passed LLVMValueRef pointer should point to enough memory to hold all of<br>
	 * the operands of the given MDNode (see LLVMGetMDNodeNumOperands) as<br>
	 * LLVMValueRefs. This memory will be populated with the LLVMValueRefs of the<br>
	 * MDNode's operands.<br>
	 * * @param V MDNode to get the operands from.<br>
	 * @param Dest Destination array for operands.<br>
	 * Original signature : <code>void LLVMGetMDNodeOperands(LLVMValueRef, LLVMValueRef*)</code>
	 */
	void LLVMGetMDNodeOperands(LLVMValueRef V, LLVMValueRef* Dest);
	/**
	 * Convert a basic block instance to a value type.<br>
	 * Original signature : <code>LLVMValueRef LLVMBasicBlockAsValue(LLVMBasicBlockRef)</code>
	 */
	LLVMValueRef LLVMBasicBlockAsValue(LLVMBasicBlockRef BB);
	/**
	 * Determine whether a LLVMValueRef is itself a basic block.<br>
	 * Original signature : <code>LLVMBool LLVMValueIsBasicBlock(LLVMValueRef)</code>
	 */
	LLVMBool LLVMValueIsBasicBlock(LLVMValueRef Val);
	/**
	 * Convert a LLVMValueRef to a LLVMBasicBlockRef instance.<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMValueAsBasicBlock(LLVMValueRef)</code>
	 */
	LLVMBasicBlockRef LLVMValueAsBasicBlock(LLVMValueRef Val);
	/**
	 * Obtain the function to which a basic block belongs.<br>
	 * * @see llvm::BasicBlock::getParent()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetBasicBlockParent(LLVMBasicBlockRef)</code>
	 */
	LLVMValueRef LLVMGetBasicBlockParent(LLVMBasicBlockRef BB);
	/**
	 * Obtain the terminator instruction for a basic block.<br>
	 * * If the basic block does not have a terminator (it is not well-formed<br>
	 * if it doesn't), then NULL is returned.<br>
	 * * The returned LLVMValueRef corresponds to a llvm::TerminatorInst.<br>
	 * * @see llvm::BasicBlock::getTerminator()<br>
	 * Original signature : <code>LLVMValueRef LLVMGetBasicBlockTerminator(LLVMBasicBlockRef)</code>
	 */
	LLVMValueRef LLVMGetBasicBlockTerminator(LLVMBasicBlockRef BB);
	/**
	 * Obtain the number of basic blocks in a function.<br>
	 * * @param Fn Function value to operate on.<br>
	 * Original signature : <code>int LLVMCountBasicBlocks(LLVMValueRef)</code>
	 */
	unsigned int LLVMCountBasicBlocks(LLVMValueRef Fn);
	/**
	 * Obtain all of the basic blocks in a function.<br>
	 * * This operates on a function value. The BasicBlocks parameter is a<br>
	 * pointer to a pre-allocated array of LLVMBasicBlockRef of at least<br>
	 * LLVMCountBasicBlocks() in length. This array is populated with<br>
	 * LLVMBasicBlockRef instances.<br>
	 * Original signature : <code>void LLVMGetBasicBlocks(LLVMValueRef, LLVMBasicBlockRef*)</code>
	 */
	void LLVMGetBasicBlocks(LLVMValueRef Fn, LLVMBasicBlockRef* BasicBlocks);
	/**
	 * Obtain the first basic block in a function.<br>
	 * * The returned basic block can be used as an iterator. You will likely<br>
	 * eventually call into LLVMGetNextBasicBlock() with it.<br>
	 * * @see llvm::Function::begin()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMGetFirstBasicBlock(LLVMValueRef)</code>
	 */
	LLVMBasicBlockRef LLVMGetFirstBasicBlock(LLVMValueRef Fn);
	/**
	 * Obtain the last basic block in a function.<br>
	 * * @see llvm::Function::end()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMGetLastBasicBlock(LLVMValueRef)</code>
	 */
	LLVMBasicBlockRef LLVMGetLastBasicBlock(LLVMValueRef Fn);
	/**
	 * Advance a basic block iterator.<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMGetNextBasicBlock(LLVMBasicBlockRef)</code>
	 */
	LLVMBasicBlockRef LLVMGetNextBasicBlock(LLVMBasicBlockRef BB);
	/**
	 * Go backwards in a basic block iterator.<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMGetPreviousBasicBlock(LLVMBasicBlockRef)</code>
	 */
	LLVMBasicBlockRef LLVMGetPreviousBasicBlock(LLVMBasicBlockRef BB);
	/**
	 * Obtain the basic block that corresponds to the entry point of a<br>
	 * function.<br>
	 * * @see llvm::Function::getEntryBlock()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMGetEntryBasicBlock(LLVMValueRef)</code>
	 */
	LLVMBasicBlockRef LLVMGetEntryBasicBlock(LLVMValueRef Fn);
	/**
	 * Append a basic block to the end of a function.<br>
	 * * @see llvm::BasicBlock::Create()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMAppendBasicBlockInContext(LLVMContextRef, LLVMValueRef, const char*)</code>
	 */
	LLVMBasicBlockRef LLVMAppendBasicBlockInContext(LLVMContextRef C, LLVMValueRef Fn, const char* Name);
	/**
	 * Append a basic block to the end of a function using the global<br>
	 * context.<br>
	 * * @see llvm::BasicBlock::Create()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMAppendBasicBlock(LLVMValueRef, const char*)</code>
	 */
	LLVMBasicBlockRef LLVMAppendBasicBlock(LLVMValueRef Fn, const char* Name);
	/**
	 * Insert a basic block in a function before another basic block.<br>
	 * * The function to add to is determined by the function of the<br>
	 * passed basic block.<br>
	 * * @see llvm::BasicBlock::Create()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMInsertBasicBlockInContext(LLVMContextRef, LLVMBasicBlockRef, const char*)</code>
	 */
	LLVMBasicBlockRef LLVMInsertBasicBlockInContext(LLVMContextRef C, LLVMBasicBlockRef BB, const char* Name);
	/**
	 * Insert a basic block in a function using the global context.<br>
	 * * @see llvm::BasicBlock::Create()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMInsertBasicBlock(LLVMBasicBlockRef, const char*)</code>
	 */
	LLVMBasicBlockRef LLVMInsertBasicBlock(LLVMBasicBlockRef InsertBeforeBB, const char* Name);
	/**
	 * Remove a basic block from a function and delete it.<br>
	 * * This deletes the basic block from its containing function and deletes<br>
	 * the basic block itself.<br>
	 * * @see llvm::BasicBlock::eraseFromParent()<br>
	 * Original signature : <code>void LLVMDeleteBasicBlock(LLVMBasicBlockRef)</code>
	 */
	void LLVMDeleteBasicBlock(LLVMBasicBlockRef BB);
	/**
	 * Remove a basic block from a function.<br>
	 * * This deletes the basic block from its containing function but keep<br>
	 * the basic block alive.<br>
	 * * @see llvm::BasicBlock::removeFromParent()<br>
	 * Original signature : <code>void LLVMRemoveBasicBlockFromParent(LLVMBasicBlockRef)</code>
	 */
	void LLVMRemoveBasicBlockFromParent(LLVMBasicBlockRef BB);
	/**
	 * Move a basic block to before another one.<br>
	 * * @see llvm::BasicBlock::moveBefore()<br>
	 * Original signature : <code>void LLVMMoveBasicBlockBefore(LLVMBasicBlockRef, LLVMBasicBlockRef)</code>
	 */
	void LLVMMoveBasicBlockBefore(LLVMBasicBlockRef BB, LLVMBasicBlockRef MovePos);
	/**
	 * Move a basic block to after another one.<br>
	 * * @see llvm::BasicBlock::moveAfter()<br>
	 * Original signature : <code>void LLVMMoveBasicBlockAfter(LLVMBasicBlockRef, LLVMBasicBlockRef)</code>
	 */
	void LLVMMoveBasicBlockAfter(LLVMBasicBlockRef BB, LLVMBasicBlockRef MovePos);
	/**
	 * Obtain the first instruction in a basic block.<br>
	 * * The returned LLVMValueRef corresponds to a llvm::Instruction<br>
	 * instance.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetFirstInstruction(LLVMBasicBlockRef)</code>
	 */
	LLVMValueRef LLVMGetFirstInstruction(LLVMBasicBlockRef BB);
	/**
	 * Obtain the last instruction in a basic block.<br>
	 * * The returned LLVMValueRef corresponds to a LLVM:Instruction.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetLastInstruction(LLVMBasicBlockRef)</code>
	 */
	LLVMValueRef LLVMGetLastInstruction(LLVMBasicBlockRef BB);
	/**
	 * Determine whether an instruction has any metadata attached.<br>
	 * Original signature : <code>int LLVMHasMetadata(LLVMValueRef)</code>
	 */
	int LLVMHasMetadata(LLVMValueRef Val);
	/**
	 * Return metadata associated with an instruction value.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetMetadata(LLVMValueRef, unsigned)</code>
	 */
	LLVMValueRef LLVMGetMetadata(LLVMValueRef Val, unsigned KindID);
	/**
	 * Set metadata associated with an instruction value.<br>
	 * Original signature : <code>void LLVMSetMetadata(LLVMValueRef, unsigned, LLVMValueRef)</code>
	 */
	void LLVMSetMetadata(LLVMValueRef Val, unsigned KindID, LLVMValueRef Node);
	/**
	 * Obtain the basic block to which an instruction belongs.<br>
	 * * @see llvm::Instruction::getParent()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMGetInstructionParent(LLVMValueRef)</code>
	 */
	LLVMBasicBlockRef LLVMGetInstructionParent(LLVMValueRef Inst);
	/**
	 * Obtain the instruction that occurs after the one specified.<br>
	 * * The next instruction will be from the same basic block.<br>
	 * * If this is the last instruction in a basic block, NULL will be<br>
	 * returned.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetNextInstruction(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetNextInstruction(LLVMValueRef Inst);
	/**
	 * Obtain the instruction that occurred before this one.<br>
	 * * If the instruction is the first instruction in a basic block, NULL<br>
	 * will be returned.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetPreviousInstruction(LLVMValueRef)</code>
	 */
	LLVMValueRef LLVMGetPreviousInstruction(LLVMValueRef Inst);
	/**
	 * Remove and delete an instruction.<br>
	 * * The instruction specified is removed from its containing building<br>
	 * block and then deleted.<br>
	 * * @see llvm::Instruction::eraseFromParent()<br>
	 * Original signature : <code>void LLVMInstructionEraseFromParent(LLVMValueRef)</code>
	 */
	void LLVMInstructionEraseFromParent(LLVMValueRef Inst);
	/**
	 * Obtain the code opcode for an individual instruction.<br>
	 * * @see llvm::Instruction::getOpCode()<br>
	 * Original signature : <code>LLVMOpcode LLVMGetInstructionOpcode(LLVMValueRef)</code>
	 */
	LLVMOpcode LLVMGetInstructionOpcode(LLVMValueRef Inst);
	/**
	 * Obtain the predicate of an instruction.<br>
	 * * This is only valid for instructions that correspond to llvm::ICmpInst<br>
	 * or llvm::ConstantExpr whose opcode is llvm::Instruction::ICmp.<br>
	 * * @see llvm::ICmpInst::getPredicate()<br>
	 * Original signature : <code>LLVMIntPredicate LLVMGetICmpPredicate(LLVMValueRef)</code>
	 */
	LLVMIntPredicate LLVMGetICmpPredicate(LLVMValueRef Inst);
	/**
	 * Set the calling convention for a call instruction.<br>
	 * * This expects an LLVMValueRef that corresponds to a llvm::CallInst or<br>
	 * llvm::InvokeInst.<br>
	 * * @see llvm::CallInst::setCallingConv()<br>
	 * @see llvm::InvokeInst::setCallingConv()<br>
	 * Original signature : <code>void LLVMSetInstructionCallConv(LLVMValueRef, unsigned)</code>
	 */
	void LLVMSetInstructionCallConv(LLVMValueRef Instr, unsigned CC);
	/**
	 * Obtain the calling convention for a call instruction.<br>
	 * * This is the opposite of LLVMSetInstructionCallConv(). Reads its<br>
	 * usage.<br>
	 * * @see LLVMSetInstructionCallConv()<br>
	 * Original signature : <code>int LLVMGetInstructionCallConv(LLVMValueRef)</code>
	 */
	unsigned int LLVMGetInstructionCallConv(LLVMValueRef Instr);
	/// Original signature : <code>void LLVMAddInstrAttribute(LLVMValueRef, unsigned, LLVMAttribute)</code>
	void LLVMAddInstrAttribute(LLVMValueRef Instr, unsigned index, LLVMAttribute LLVMAttribute1);
	/// Original signature : <code>void LLVMRemoveInstrAttribute(LLVMValueRef, unsigned, LLVMAttribute)</code>
	void LLVMRemoveInstrAttribute(LLVMValueRef Instr, unsigned index, LLVMAttribute LLVMAttribute1);
	/// Original signature : <code>void LLVMSetInstrParamAlignment(LLVMValueRef, unsigned, unsigned)</code>
	void LLVMSetInstrParamAlignment(LLVMValueRef Instr, unsigned index, unsigned align);
	/**
	 * Obtain whether a call instruction is a tail call.<br>
	 * * This only works on llvm::CallInst instructions.<br>
	 * * @see llvm::CallInst::isTailCall()<br>
	 * Original signature : <code>LLVMBool LLVMIsTailCall(LLVMValueRef)</code>
	 */
	LLVMBool LLVMIsTailCall(LLVMValueRef CallInst);
	/**
	 * Set whether a call instruction is a tail call.<br>
	 * * This only works on llvm::CallInst instructions.<br>
	 * * @see llvm::CallInst::setTailCall()<br>
	 * Original signature : <code>void LLVMSetTailCall(LLVMValueRef, LLVMBool)</code>
	 */
	void LLVMSetTailCall(LLVMValueRef CallInst, LLVMBool IsTailCall);
	/**
	 * Obtain the default destination basic block of a switch instruction.<br>
	 * * This only works on llvm::SwitchInst instructions.<br>
	 * * @see llvm::SwitchInst::getDefaultDest()<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMGetSwitchDefaultDest(LLVMValueRef)</code>
	 */
	LLVMBasicBlockRef LLVMGetSwitchDefaultDest(LLVMValueRef SwitchInstr);
	/**
	 * Add an incoming value to the end of a PHI list.<br>
	 * Original signature : <code>void LLVMAddIncoming(LLVMValueRef, LLVMValueRef*, LLVMBasicBlockRef*, unsigned)</code>
	 */
	void LLVMAddIncoming(LLVMValueRef PhiNode, LLVMValueRef* IncomingValues, LLVMBasicBlockRef* IncomingBlocks, unsigned Count);
	/**
	 * Obtain the number of incoming basic blocks to a PHI node.<br>
	 * Original signature : <code>int LLVMCountIncoming(LLVMValueRef)</code>
	 */
	unsigned int LLVMCountIncoming(LLVMValueRef PhiNode);
	/**
	 * Obtain an incoming value to a PHI node as a LLVMValueRef.<br>
	 * Original signature : <code>LLVMValueRef LLVMGetIncomingValue(LLVMValueRef, unsigned)</code>
	 */
	LLVMValueRef LLVMGetIncomingValue(LLVMValueRef PhiNode, unsigned Index);
	/**
	 * Obtain an incoming value to a PHI node as a LLVMBasicBlockRef.<br>
	 * Original signature : <code>LLVMBasicBlockRef LLVMGetIncomingBlock(LLVMValueRef, unsigned)</code>
	 */
	LLVMBasicBlockRef LLVMGetIncomingBlock(LLVMValueRef PhiNode, unsigned Index);
	/// Original signature : <code>LLVMBuilderRef LLVMCreateBuilderInContext(LLVMContextRef)</code>
	LLVMBuilderRef LLVMCreateBuilderInContext(LLVMContextRef C);
	/// Original signature : <code>LLVMBuilderRef LLVMCreateBuilder()</code>
	LLVMBuilderRef LLVMCreateBuilder();
	/// Original signature : <code>void LLVMPositionBuilder(LLVMBuilderRef, LLVMBasicBlockRef, LLVMValueRef)</code>
	void LLVMPositionBuilder(LLVMBuilderRef Builder, LLVMBasicBlockRef Block, LLVMValueRef Instr);
	/// Original signature : <code>void LLVMPositionBuilderBefore(LLVMBuilderRef, LLVMValueRef)</code>
	void LLVMPositionBuilderBefore(LLVMBuilderRef Builder, LLVMValueRef Instr);
	/// Original signature : <code>void LLVMPositionBuilderAtEnd(LLVMBuilderRef, LLVMBasicBlockRef)</code>
	void LLVMPositionBuilderAtEnd(LLVMBuilderRef Builder, LLVMBasicBlockRef Block);
	/// Original signature : <code>LLVMBasicBlockRef LLVMGetInsertBlock(LLVMBuilderRef)</code>
	LLVMBasicBlockRef LLVMGetInsertBlock(LLVMBuilderRef Builder);
	/// Original signature : <code>void LLVMClearInsertionPosition(LLVMBuilderRef)</code>
	void LLVMClearInsertionPosition(LLVMBuilderRef Builder);
	/// Original signature : <code>void LLVMInsertIntoBuilder(LLVMBuilderRef, LLVMValueRef)</code>
	void LLVMInsertIntoBuilder(LLVMBuilderRef Builder, LLVMValueRef Instr);
	/// Original signature : <code>void LLVMInsertIntoBuilderWithName(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	void LLVMInsertIntoBuilderWithName(LLVMBuilderRef Builder, LLVMValueRef Instr, const char* Name);
	/// Original signature : <code>void LLVMDisposeBuilder(LLVMBuilderRef)</code>
	void LLVMDisposeBuilder(LLVMBuilderRef Builder);
	/**
	 * Metadata<br>
	 * Original signature : <code>void LLVMSetCurrentDebugLocation(LLVMBuilderRef, LLVMValueRef)</code>
	 */
	void LLVMSetCurrentDebugLocation(LLVMBuilderRef Builder, LLVMValueRef L);
	/// Original signature : <code>LLVMValueRef LLVMGetCurrentDebugLocation(LLVMBuilderRef)</code>
	LLVMValueRef LLVMGetCurrentDebugLocation(LLVMBuilderRef Builder);
	/// Original signature : <code>void LLVMSetInstDebugLocation(LLVMBuilderRef, LLVMValueRef)</code>
	void LLVMSetInstDebugLocation(LLVMBuilderRef Builder, LLVMValueRef Inst);
	/**
	 * Terminators<br>
	 * Original signature : <code>LLVMValueRef LLVMBuildRetVoid(LLVMBuilderRef)</code>
	 */
	LLVMValueRef LLVMBuildRetVoid(LLVMBuilderRef LLVMBuilderRef1);
	/// Original signature : <code>LLVMValueRef LLVMBuildRet(LLVMBuilderRef, LLVMValueRef)</code>
	LLVMValueRef LLVMBuildRet(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef V);
	/// Original signature : <code>LLVMValueRef LLVMBuildAggregateRet(LLVMBuilderRef, LLVMValueRef*, unsigned)</code>
	LLVMValueRef LLVMBuildAggregateRet(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef* RetVals, unsigned N);
	/// Original signature : <code>LLVMValueRef LLVMBuildBr(LLVMBuilderRef, LLVMBasicBlockRef)</code>
	LLVMValueRef LLVMBuildBr(LLVMBuilderRef LLVMBuilderRef1, LLVMBasicBlockRef Dest);
	/// Original signature : <code>LLVMValueRef LLVMBuildCondBr(LLVMBuilderRef, LLVMValueRef, LLVMBasicBlockRef, LLVMBasicBlockRef)</code>
	LLVMValueRef LLVMBuildCondBr(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef If, LLVMBasicBlockRef Then, LLVMBasicBlockRef Else);
	/// Original signature : <code>LLVMValueRef LLVMBuildSwitch(LLVMBuilderRef, LLVMValueRef, LLVMBasicBlockRef, unsigned)</code>
	LLVMValueRef LLVMBuildSwitch(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef V, LLVMBasicBlockRef Else, unsigned NumCases);
	/// Original signature : <code>LLVMValueRef LLVMBuildIndirectBr(LLVMBuilderRef, LLVMValueRef, unsigned)</code>
	LLVMValueRef LLVMBuildIndirectBr(LLVMBuilderRef B, LLVMValueRef Addr, unsigned NumDests);
	/// Original signature : <code>LLVMValueRef LLVMBuildInvoke(LLVMBuilderRef, LLVMValueRef, LLVMValueRef*, unsigned, LLVMBasicBlockRef, LLVMBasicBlockRef, const char*)</code>
	LLVMValueRef LLVMBuildInvoke(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Fn, LLVMValueRef* Args, unsigned NumArgs, LLVMBasicBlockRef Then, LLVMBasicBlockRef Catch, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildLandingPad(LLVMBuilderRef, LLVMTypeRef, LLVMValueRef, unsigned, const char*)</code>
	LLVMValueRef LLVMBuildLandingPad(LLVMBuilderRef B, LLVMTypeRef Ty, LLVMValueRef PersFn, unsigned NumClauses, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildResume(LLVMBuilderRef, LLVMValueRef)</code>
	LLVMValueRef LLVMBuildResume(LLVMBuilderRef B, LLVMValueRef Exn);
	/// Original signature : <code>LLVMValueRef LLVMBuildUnreachable(LLVMBuilderRef)</code>
	LLVMValueRef LLVMBuildUnreachable(LLVMBuilderRef LLVMBuilderRef1);
	/**
	 * Add a case to the switch instruction<br>
	 * Original signature : <code>void LLVMAddCase(LLVMValueRef, LLVMValueRef, LLVMBasicBlockRef)</code>
	 */
	void LLVMAddCase(LLVMValueRef Switch, LLVMValueRef OnVal, LLVMBasicBlockRef Dest);
	/**
	 * Add a destination to the indirectbr instruction<br>
	 * Original signature : <code>void LLVMAddDestination(LLVMValueRef, LLVMBasicBlockRef)</code>
	 */
	void LLVMAddDestination(LLVMValueRef IndirectBr, LLVMBasicBlockRef Dest);
	/**
	 * Add a catch or filter clause to the landingpad instruction<br>
	 * Original signature : <code>void LLVMAddClause(LLVMValueRef, LLVMValueRef)</code>
	 */
	void LLVMAddClause(LLVMValueRef LandingPad, LLVMValueRef ClauseVal);
	/**
	 * Set the 'cleanup' flag in the landingpad instruction<br>
	 * Original signature : <code>void LLVMSetCleanup(LLVMValueRef, LLVMBool)</code>
	 */
	void LLVMSetCleanup(LLVMValueRef LandingPad, LLVMBool Val);
	/**
	 * Arithmetic<br>
	 * Original signature : <code>LLVMValueRef LLVMBuildAdd(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	 */
	LLVMValueRef LLVMBuildAdd(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNSWAdd(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNSWAdd(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNUWAdd(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNUWAdd(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFAdd(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildFAdd(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildSub(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildSub(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNSWSub(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNSWSub(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNUWSub(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNUWSub(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFSub(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildFSub(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildMul(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildMul(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNSWMul(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNSWMul(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNUWMul(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNUWMul(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFMul(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildFMul(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildUDiv(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildUDiv(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildSDiv(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildSDiv(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildExactSDiv(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildExactSDiv(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFDiv(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildFDiv(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildURem(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildURem(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildSRem(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildSRem(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFRem(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildFRem(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildShl(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildShl(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildLShr(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildLShr(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildAShr(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildAShr(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildAnd(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildAnd(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildOr(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildOr(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildXor(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildXor(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildBinOp(LLVMBuilderRef, LLVMOpcode, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildBinOp(LLVMBuilderRef B, LLVMOpcode Op, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNeg(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNeg(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef V, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNSWNeg(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNSWNeg(LLVMBuilderRef B, LLVMValueRef V, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNUWNeg(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNUWNeg(LLVMBuilderRef B, LLVMValueRef V, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFNeg(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildFNeg(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef V, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildNot(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildNot(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef V, const char* Name);
	/**
	 * Memory<br>
	 * Original signature : <code>LLVMValueRef LLVMBuildMalloc(LLVMBuilderRef, LLVMTypeRef, const char*)</code>
	 */
	LLVMValueRef LLVMBuildMalloc(LLVMBuilderRef LLVMBuilderRef1, LLVMTypeRef Ty, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildArrayMalloc(LLVMBuilderRef, LLVMTypeRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildArrayMalloc(LLVMBuilderRef LLVMBuilderRef1, LLVMTypeRef Ty, LLVMValueRef Val, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildAlloca(LLVMBuilderRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildAlloca(LLVMBuilderRef LLVMBuilderRef1, LLVMTypeRef Ty, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildArrayAlloca(LLVMBuilderRef, LLVMTypeRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildArrayAlloca(LLVMBuilderRef LLVMBuilderRef1, LLVMTypeRef Ty, LLVMValueRef Val, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFree(LLVMBuilderRef, LLVMValueRef)</code>
	LLVMValueRef LLVMBuildFree(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef PointerVal);
	/// Original signature : <code>LLVMValueRef LLVMBuildLoad(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildLoad(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef PointerVal, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildStore(LLVMBuilderRef, LLVMValueRef, LLVMValueRef)</code>
	LLVMValueRef LLVMBuildStore(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMValueRef Ptr);
	/// Original signature : <code>LLVMValueRef LLVMBuildGEP(LLVMBuilderRef, LLVMValueRef, LLVMValueRef*, unsigned, const char*)</code>
	LLVMValueRef LLVMBuildGEP(LLVMBuilderRef B, LLVMValueRef Pointer, LLVMValueRef* Indices, unsigned NumIndices, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildInBoundsGEP(LLVMBuilderRef, LLVMValueRef, LLVMValueRef*, unsigned, const char*)</code>
	LLVMValueRef LLVMBuildInBoundsGEP(LLVMBuilderRef B, LLVMValueRef Pointer, LLVMValueRef* Indices, unsigned NumIndices, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildStructGEP(LLVMBuilderRef, LLVMValueRef, unsigned, const char*)</code>
	LLVMValueRef LLVMBuildStructGEP(LLVMBuilderRef B, LLVMValueRef Pointer, unsigned Idx, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildGlobalString(LLVMBuilderRef, const char*, const char*)</code>
	LLVMValueRef LLVMBuildGlobalString(LLVMBuilderRef B, const char* Str, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildGlobalStringPtr(LLVMBuilderRef, const char*, const char*)</code>
	LLVMValueRef LLVMBuildGlobalStringPtr(LLVMBuilderRef B, const char* Str, const char* Name);
	/// Original signature : <code>LLVMBool LLVMGetVolatile(LLVMValueRef)</code>
	LLVMBool LLVMGetVolatile(LLVMValueRef MemoryAccessInst);
	/// Original signature : <code>void LLVMSetVolatile(LLVMValueRef, LLVMBool)</code>
	void LLVMSetVolatile(LLVMValueRef MemoryAccessInst, LLVMBool IsVolatile);
	/**
	 * Casts<br>
	 * Original signature : <code>LLVMValueRef LLVMBuildTrunc(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	 */
	LLVMValueRef LLVMBuildTrunc(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildZExt(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildZExt(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildSExt(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildSExt(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFPToUI(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildFPToUI(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFPToSI(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildFPToSI(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildUIToFP(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildUIToFP(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildSIToFP(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildSIToFP(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFPTrunc(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildFPTrunc(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFPExt(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildFPExt(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildPtrToInt(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildPtrToInt(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildIntToPtr(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildIntToPtr(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildBitCast(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildBitCast(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildZExtOrBitCast(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildZExtOrBitCast(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildSExtOrBitCast(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildSExtOrBitCast(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildTruncOrBitCast(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildTruncOrBitCast(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildCast(LLVMBuilderRef, LLVMOpcode, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildCast(LLVMBuilderRef B, LLVMOpcode Op, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildPointerCast(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildPointerCast(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/**
	 * Signed cast!<br>
	 * Original signature : <code>LLVMValueRef LLVMBuildIntCast(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code><br>
	 * @param LLVMBuilderRef1 Signed cast!<br>
	 * @param Val Signed cast!
	 */
	LLVMValueRef LLVMBuildIntCast(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFPCast(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildFPCast(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, LLVMTypeRef DestTy, const char* Name);
	/**
	 * Comparisons<br>
	 * Original signature : <code>LLVMValueRef LLVMBuildICmp(LLVMBuilderRef, LLVMIntPredicate, LLVMValueRef, LLVMValueRef, const char*)</code>
	 */
	LLVMValueRef LLVMBuildICmp(LLVMBuilderRef LLVMBuilderRef1, LLVMIntPredicate Op, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildFCmp(LLVMBuilderRef, LLVMRealPredicate, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildFCmp(LLVMBuilderRef LLVMBuilderRef1, LLVMRealPredicate Op, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/**
	 * Miscellaneous instructions<br>
	 * Original signature : <code>LLVMValueRef LLVMBuildPhi(LLVMBuilderRef, LLVMTypeRef, const char*)</code>
	 */
	LLVMValueRef LLVMBuildPhi(LLVMBuilderRef LLVMBuilderRef1, LLVMTypeRef Ty, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildCall(LLVMBuilderRef, LLVMValueRef, LLVMValueRef*, unsigned, const char*)</code>
	LLVMValueRef LLVMBuildCall(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Fn, LLVMValueRef* Args, unsigned NumArgs, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildSelect(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildSelect(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef If, LLVMValueRef Then, LLVMValueRef Else, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildVAArg(LLVMBuilderRef, LLVMValueRef, LLVMTypeRef, const char*)</code>
	LLVMValueRef LLVMBuildVAArg(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef List, LLVMTypeRef Ty, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildExtractElement(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildExtractElement(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef VecVal, LLVMValueRef Index, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildInsertElement(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildInsertElement(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef VecVal, LLVMValueRef EltVal, LLVMValueRef Index, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildShuffleVector(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildShuffleVector(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef V1, LLVMValueRef V2, LLVMValueRef Mask, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildExtractValue(LLVMBuilderRef, LLVMValueRef, unsigned, const char*)</code>
	LLVMValueRef LLVMBuildExtractValue(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef AggVal, unsigned Index, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildInsertValue(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, unsigned, const char*)</code>
	LLVMValueRef LLVMBuildInsertValue(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef AggVal, LLVMValueRef EltVal, unsigned Index, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildIsNull(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildIsNull(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildIsNotNull(LLVMBuilderRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildIsNotNull(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef Val, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildPtrDiff(LLVMBuilderRef, LLVMValueRef, LLVMValueRef, const char*)</code>
	LLVMValueRef LLVMBuildPtrDiff(LLVMBuilderRef LLVMBuilderRef1, LLVMValueRef LHS, LLVMValueRef RHS, const char* Name);
	/// Original signature : <code>LLVMValueRef LLVMBuildAtomicRMW(LLVMBuilderRef, LLVMAtomicRMWBinOp, LLVMValueRef, LLVMValueRef, LLVMAtomicOrdering, LLVMBool)</code>
	LLVMValueRef LLVMBuildAtomicRMW(LLVMBuilderRef B, LLVMAtomicRMWBinOp op, LLVMValueRef PTR, LLVMValueRef Val, LLVMAtomicOrdering ordering, LLVMBool singleThread);
	/**
	 * Changes the type of M so it can be passed to FunctionPassManagers and the<br>
	 * JIT.  They take ModuleProviders for historical reasons.<br>
	 * Original signature : <code>LLVMModuleProviderRef LLVMCreateModuleProviderForExistingModule(LLVMModuleRef)</code>
	 */
	LLVMModuleProviderRef LLVMCreateModuleProviderForExistingModule(LLVMModuleRef M);
	/**
	 * Destroys the module M.<br>
	 * Original signature : <code>void LLVMDisposeModuleProvider(LLVMModuleProviderRef)</code>
	 */
	void LLVMDisposeModuleProvider(LLVMModuleProviderRef M);
	/// Original signature : <code>LLVMBool LLVMCreateMemoryBufferWithContentsOfFile(const char*, LLVMMemoryBufferRef*, char**)</code>
	LLVMBool LLVMCreateMemoryBufferWithContentsOfFile(const char* Path, LLVMMemoryBufferRef* OutMemBuf, char** OutMessage);
	/// Original signature : <code>LLVMBool LLVMCreateMemoryBufferWithSTDIN(LLVMMemoryBufferRef*, char**)</code>
	LLVMBool LLVMCreateMemoryBufferWithSTDIN(LLVMMemoryBufferRef* OutMemBuf, char** OutMessage);
	/// Original signature : <code>LLVMMemoryBufferRef LLVMCreateMemoryBufferWithMemoryRange(const char*, size_t, const char*, LLVMBool)</code>
	LLVMMemoryBufferRef LLVMCreateMemoryBufferWithMemoryRange(const char* InputData, size_t InputDataLength, const char* BufferName, LLVMBool RequiresNullTerminator);
	/// Original signature : <code>LLVMMemoryBufferRef LLVMCreateMemoryBufferWithMemoryRangeCopy(const char*, size_t, const char*)</code>
	LLVMMemoryBufferRef LLVMCreateMemoryBufferWithMemoryRangeCopy(const char* InputData, size_t InputDataLength, const char* BufferName);
	/// Original signature : <code>char* LLVMGetBufferStart(LLVMMemoryBufferRef)</code>
	const char* LLVMGetBufferStart(LLVMMemoryBufferRef MemBuf);
	/// Original signature : <code>size_t LLVMGetBufferSize(LLVMMemoryBufferRef)</code>
	size_t LLVMGetBufferSize(LLVMMemoryBufferRef MemBuf);
	/// Original signature : <code>void LLVMDisposeMemoryBuffer(LLVMMemoryBufferRef)</code>
	void LLVMDisposeMemoryBuffer(LLVMMemoryBufferRef MemBuf);
	/**
	 * Return the global pass registry, for use with initialization functions.<br>
	 * @see llvm::PassRegistry::getPassRegistry<br>
	 * Original signature : <code>LLVMPassRegistryRef LLVMGetGlobalPassRegistry()</code>
	 */
	LLVMPassRegistryRef LLVMGetGlobalPassRegistry();
	/**
	 * Constructs a new whole-module pass pipeline. This type of pipeline is<br>
	 * suitable for link-time optimization and whole-module transformations.<br>
	 * @see llvm::PassManager::PassManager<br>
	 * Original signature : <code>LLVMPassManagerRef LLVMCreatePassManager()</code>
	 */
	LLVMPassManagerRef LLVMCreatePassManager();
	/**
	 * Constructs a new function-by-function pass pipeline over the module<br>
	 * provider. It does not take ownership of the module provider. This type of<br>
	 * pipeline is suitable for code generation and JIT compilation tasks.<br>
	 * @see llvm::FunctionPassManager::FunctionPassManager<br>
	 * Original signature : <code>LLVMPassManagerRef LLVMCreateFunctionPassManagerForModule(LLVMModuleRef)</code>
	 */
	LLVMPassManagerRef LLVMCreateFunctionPassManagerForModule(LLVMModuleRef M);
	/**
	 * Deprecated: Use LLVMCreateFunctionPassManagerForModule instead.<br>
	 * Original signature : <code>LLVMPassManagerRef LLVMCreateFunctionPassManager(LLVMModuleProviderRef)</code>
	 */
	LLVMPassManagerRef LLVMCreateFunctionPassManager(LLVMModuleProviderRef MP);
	/**
	 * Initializes, executes on the provided module, and finalizes all of the<br>
	 * passes scheduled in the pass manager. Returns 1 if any of the passes<br>
	 * modified the module, 0 otherwise.<br>
	 * @see llvm::PassManager::run(Module&)<br>
	 * Original signature : <code>LLVMBool LLVMRunPassManager(LLVMPassManagerRef, LLVMModuleRef)</code>
	 */
	LLVMBool LLVMRunPassManager(LLVMPassManagerRef PM, LLVMModuleRef M);
	/**
	 * Initializes all of the function passes scheduled in the function pass<br>
	 * manager. Returns 1 if any of the passes modified the module, 0 otherwise.<br>
	 * @see llvm::FunctionPassManager::doInitialization<br>
	 * Original signature : <code>LLVMBool LLVMInitializeFunctionPassManager(LLVMPassManagerRef)</code>
	 */
	LLVMBool LLVMInitializeFunctionPassManager(LLVMPassManagerRef FPM);
	/**
	 * Executes all of the function passes scheduled in the function pass manager<br>
	 * on the provided function. Returns 1 if any of the passes modified the<br>
	 * function, false otherwise.<br>
	 * @see llvm::FunctionPassManager::run(Function&)<br>
	 * Original signature : <code>LLVMBool LLVMRunFunctionPassManager(LLVMPassManagerRef, LLVMValueRef)</code>
	 */
	LLVMBool LLVMRunFunctionPassManager(LLVMPassManagerRef FPM, LLVMValueRef F);
	/**
	 * Finalizes all of the function passes scheduled in in the function pass<br>
	 * manager. Returns 1 if any of the passes modified the module, 0 otherwise.<br>
	 * @see llvm::FunctionPassManager::doFinalization<br>
	 * Original signature : <code>LLVMBool LLVMFinalizeFunctionPassManager(LLVMPassManagerRef)</code>
	 */
	LLVMBool LLVMFinalizeFunctionPassManager(LLVMPassManagerRef FPM);
	/**
	 * Frees the memory of a pass pipeline. For function pipelines, does not free<br>
	 * the module provider.<br>
	 * @see llvm::PassManagerBase::~PassManagerBase.<br>
	 * Original signature : <code>void LLVMDisposePassManager(LLVMPassManagerRef)</code>
	 */
	void LLVMDisposePassManager(LLVMPassManagerRef PM);
	/**
	 * Allocate and initialize structures needed to make LLVM safe for<br>
	 * multithreading. The return value indicates whether multithreaded<br>
	 * initialization succeeded. Must be executed in isolation from all<br>
	 * other LLVM api calls.<br>
	 * @see llvm::llvm_start_multithreaded<br>
	 * Original signature : <code>LLVMBool LLVMStartMultithreaded()</code>
	 */
	LLVMBool LLVMStartMultithreaded();
	/**
	 * Deallocate structures necessary to make LLVM safe for multithreading.<br>
	 * Must be executed in isolation from all other LLVM api calls.<br>
	 * @see llvm::llvm_stop_multithreaded<br>
	 * Original signature : <code>void LLVMStopMultithreaded()</code>
	 */
	void LLVMStopMultithreaded();
	/**
	 * Check whether LLVM is executing in thread-safe mode or not.<br>
	 * @see llvm::llvm_is_multithreaded<br>
	 * Original signature : <code>LLVMBool LLVMIsMultithreaded()</code>
	 */
	LLVMBool LLVMIsMultithreaded();
}
extern ""C"" {

}
extern ""C"" {
typedef unsigned int uintptr_t;
	typedef char* va_list;
}
typedef unsigned int size_t;
typedef size_t rsize_t;
typedef int intptr_t;
typedef int ptrdiff_t;
typedef unsigned short wint_t;
typedef unsigned short wctype_t;
