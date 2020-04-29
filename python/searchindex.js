Search.setIndex({docnames:["gtirb","gtirb.auxdata","gtirb.block","gtirb.byteinterval","gtirb.cfg","gtirb.ir","gtirb.module","gtirb.node","gtirb.offset","gtirb.proto","gtirb.proto.AuxData_pb2","gtirb.proto.ByteInterval_pb2","gtirb.proto.CFG_pb2","gtirb.proto.CodeBlock_pb2","gtirb.proto.DataBlock_pb2","gtirb.proto.IR_pb2","gtirb.proto.Module_pb2","gtirb.proto.Offset_pb2","gtirb.proto.ProxyBlock_pb2","gtirb.proto.Section_pb2","gtirb.proto.Symbol_pb2","gtirb.proto.SymbolicExpression_pb2","gtirb.section","gtirb.serialization","gtirb.symbol","gtirb.symbolicexpression","gtirb.util","gtirb.version","index"],envversion:{"sphinx.domains.c":2,"sphinx.domains.changeset":1,"sphinx.domains.citation":1,"sphinx.domains.cpp":2,"sphinx.domains.index":1,"sphinx.domains.javascript":2,"sphinx.domains.math":2,"sphinx.domains.python":2,"sphinx.domains.rst":2,"sphinx.domains.std":1,"sphinx.ext.todo":2,"sphinx.ext.viewcode":1,sphinx:56},filenames:["gtirb.rst","gtirb.auxdata.rst","gtirb.block.rst","gtirb.byteinterval.rst","gtirb.cfg.rst","gtirb.ir.rst","gtirb.module.rst","gtirb.node.rst","gtirb.offset.rst","gtirb.proto.rst","gtirb.proto.AuxData_pb2.rst","gtirb.proto.ByteInterval_pb2.rst","gtirb.proto.CFG_pb2.rst","gtirb.proto.CodeBlock_pb2.rst","gtirb.proto.DataBlock_pb2.rst","gtirb.proto.IR_pb2.rst","gtirb.proto.Module_pb2.rst","gtirb.proto.Offset_pb2.rst","gtirb.proto.ProxyBlock_pb2.rst","gtirb.proto.Section_pb2.rst","gtirb.proto.Symbol_pb2.rst","gtirb.proto.SymbolicExpression_pb2.rst","gtirb.section.rst","gtirb.serialization.rst","gtirb.symbol.rst","gtirb.symbolicexpression.rst","gtirb.util.rst","gtirb.version.rst","index.rst"],objects:{"":{gtirb:[0,0,0,"-"]},"gtirb.AuxData":{__init__:[0,2,1,""],serializer:[0,3,1,""]},"gtirb.AuxDataContainer":{__init__:[0,2,1,""],deep_eq:[0,2,1,""]},"gtirb.Block":{references:[0,2,1,""]},"gtirb.ByteBlock":{__init__:[0,2,1,""],address:[0,2,1,""],byte_interval:[0,2,1,""],contents:[0,2,1,""],deep_eq:[0,2,1,""],references:[0,2,1,""]},"gtirb.ByteInterval":{__init__:[0,2,1,""],byte_blocks_at:[0,2,1,""],byte_blocks_on:[0,2,1,""],code_blocks_at:[0,2,1,""],code_blocks_on:[0,2,1,""],data_blocks_at:[0,2,1,""],data_blocks_on:[0,2,1,""],deep_eq:[0,2,1,""],initialized_size:[0,2,1,""],section:[0,2,1,""],symbolic_expressions_at:[0,2,1,""]},"gtirb.CfgNode":{incoming_edges:[0,2,1,""],outgoing_edges:[0,2,1,""]},"gtirb.CodeBlock":{__init__:[0,2,1,""],deep_eq:[0,2,1,""],incoming_edges:[0,2,1,""],outgoing_edges:[0,2,1,""]},"gtirb.DataBlock":{__init__:[0,2,1,""]},"gtirb.Edge":{Label:[0,1,1,""],Type:[0,1,1,""],__eq__:[0,2,1,""],__hash__:[0,2,1,""],__init__:[0,2,1,""],deep_eq:[0,2,1,""]},"gtirb.Edge.Label":{__eq__:[0,2,1,""],__hash__:[0,2,1,""],__init__:[0,2,1,""]},"gtirb.Edge.Type":{Branch:[0,3,1,""],Call:[0,3,1,""],Fallthrough:[0,3,1,""],Return:[0,3,1,""],Syscall:[0,3,1,""],Sysret:[0,3,1,""]},"gtirb.IR":{__init__:[0,2,1,""],byte_blocks:[0,2,1,""],byte_blocks_at:[0,2,1,""],byte_blocks_on:[0,2,1,""],byte_intervals:[0,2,1,""],byte_intervals_at:[0,2,1,""],byte_intervals_on:[0,2,1,""],cfg_nodes:[0,2,1,""],code_blocks:[0,2,1,""],code_blocks_at:[0,2,1,""],code_blocks_on:[0,2,1,""],data_blocks:[0,2,1,""],data_blocks_at:[0,2,1,""],data_blocks_on:[0,2,1,""],deep_eq:[0,2,1,""],load_protobuf:[0,2,1,""],load_protobuf_file:[0,2,1,""],modules_at:[0,2,1,""],modules_on:[0,2,1,""],proxy_blocks:[0,2,1,""],save_protobuf:[0,2,1,""],save_protobuf_file:[0,2,1,""],sections:[0,2,1,""],sections_at:[0,2,1,""],sections_on:[0,2,1,""],symbolic_expressions_at:[0,2,1,""],symbols:[0,2,1,""]},"gtirb.Module":{FileFormat:[0,1,1,""],ISA:[0,1,1,""],__init__:[0,2,1,""],address:[0,2,1,""],byte_blocks:[0,2,1,""],byte_blocks_at:[0,2,1,""],byte_blocks_on:[0,2,1,""],byte_intervals:[0,2,1,""],byte_intervals_at:[0,2,1,""],byte_intervals_on:[0,2,1,""],cfg_nodes:[0,2,1,""],code_blocks:[0,2,1,""],code_blocks_at:[0,2,1,""],code_blocks_on:[0,2,1,""],data_blocks:[0,2,1,""],data_blocks_at:[0,2,1,""],data_blocks_on:[0,2,1,""],deep_eq:[0,2,1,""],ir:[0,2,1,""],sections_at:[0,2,1,""],sections_on:[0,2,1,""],size:[0,2,1,""],symbolic_expressions_at:[0,2,1,""]},"gtirb.Module.FileFormat":{COFF:[0,3,1,""],ELF:[0,3,1,""],IdaProDb32:[0,3,1,""],IdaProDb64:[0,3,1,""],MACHO:[0,3,1,""],PE:[0,3,1,""],RAW:[0,3,1,""],Undefined:[0,3,1,""],XCOFF:[0,3,1,""]},"gtirb.Module.ISA":{ARM64:[0,3,1,""],ARM:[0,3,1,""],IA32:[0,3,1,""],MIPS32:[0,3,1,""],MIPS64:[0,3,1,""],PPC32:[0,3,1,""],PPC64:[0,3,1,""],Undefined:[0,3,1,""],ValidButUnsupported:[0,3,1,""],X64:[0,3,1,""]},"gtirb.Node":{__init__:[0,2,1,""],deep_eq:[0,2,1,""],from_uuid:[0,2,1,""]},"gtirb.Offset":{__init__:[0,2,1,""]},"gtirb.ProxyBlock":{__init__:[0,2,1,""],deep_eq:[0,2,1,""],incoming_edges:[0,2,1,""],module:[0,2,1,""],outgoing_edges:[0,2,1,""],references:[0,2,1,""]},"gtirb.Section":{Flag:[0,1,1,""],__init__:[0,2,1,""],address:[0,2,1,""],byte_blocks:[0,2,1,""],byte_blocks_at:[0,2,1,""],byte_blocks_on:[0,2,1,""],byte_intervals_at:[0,2,1,""],byte_intervals_on:[0,2,1,""],code_blocks:[0,2,1,""],code_blocks_at:[0,2,1,""],code_blocks_on:[0,2,1,""],data_blocks:[0,2,1,""],data_blocks_at:[0,2,1,""],data_blocks_on:[0,2,1,""],deep_eq:[0,2,1,""],module:[0,2,1,""],size:[0,2,1,""],symbolic_expressions_at:[0,2,1,""]},"gtirb.Section.Flag":{Executable:[0,3,1,""],Initialized:[0,3,1,""],Loaded:[0,3,1,""],Readable:[0,3,1,""],ThreadLocal:[0,3,1,""],Undefined:[0,3,1,""],Writable:[0,3,1,""]},"gtirb.Serialization":{__init__:[0,2,1,""],decode:[0,2,1,""],encode:[0,2,1,""]},"gtirb.SymAddrAddr":{__eq__:[0,2,1,""],__hash__:[0,2,1,""],__init__:[0,2,1,""],deep_eq:[0,2,1,""]},"gtirb.SymAddrConst":{__eq__:[0,2,1,""],__hash__:[0,2,1,""],__init__:[0,2,1,""],deep_eq:[0,2,1,""]},"gtirb.SymStackConst":{__eq__:[0,2,1,""],__hash__:[0,2,1,""],__init__:[0,2,1,""],deep_eq:[0,2,1,""]},"gtirb.Symbol":{__init__:[0,2,1,""],deep_eq:[0,2,1,""],module:[0,2,1,""],referent:[0,2,1,""],value:[0,2,1,""]},"gtirb.auxdata":{AuxData:[1,1,1,""],AuxDataContainer:[1,1,1,""]},"gtirb.auxdata.AuxData":{__init__:[1,2,1,""],serializer:[1,3,1,""]},"gtirb.auxdata.AuxDataContainer":{__init__:[1,2,1,""],deep_eq:[1,2,1,""]},"gtirb.block":{Block:[2,1,1,""],ByteBlock:[2,1,1,""],CfgNode:[2,1,1,""],CodeBlock:[2,1,1,""],DataBlock:[2,1,1,""],ProxyBlock:[2,1,1,""]},"gtirb.block.Block":{references:[2,2,1,""]},"gtirb.block.ByteBlock":{__init__:[2,2,1,""],address:[2,2,1,""],byte_interval:[2,2,1,""],contents:[2,2,1,""],deep_eq:[2,2,1,""],references:[2,2,1,""]},"gtirb.block.CfgNode":{incoming_edges:[2,2,1,""],outgoing_edges:[2,2,1,""]},"gtirb.block.CodeBlock":{__init__:[2,2,1,""],deep_eq:[2,2,1,""],incoming_edges:[2,2,1,""],outgoing_edges:[2,2,1,""]},"gtirb.block.DataBlock":{__init__:[2,2,1,""]},"gtirb.block.ProxyBlock":{__init__:[2,2,1,""],deep_eq:[2,2,1,""],incoming_edges:[2,2,1,""],module:[2,2,1,""],outgoing_edges:[2,2,1,""],references:[2,2,1,""]},"gtirb.byteinterval":{ByteInterval:[3,1,1,""]},"gtirb.byteinterval.ByteInterval":{__init__:[3,2,1,""],byte_blocks_at:[3,2,1,""],byte_blocks_on:[3,2,1,""],code_blocks_at:[3,2,1,""],code_blocks_on:[3,2,1,""],data_blocks_at:[3,2,1,""],data_blocks_on:[3,2,1,""],deep_eq:[3,2,1,""],initialized_size:[3,2,1,""],section:[3,2,1,""],symbolic_expressions_at:[3,2,1,""]},"gtirb.cfg":{Edge:[4,1,1,""]},"gtirb.cfg.Edge":{Label:[4,1,1,""],Type:[4,1,1,""],__eq__:[4,2,1,""],__hash__:[4,2,1,""],__init__:[4,2,1,""],deep_eq:[4,2,1,""]},"gtirb.cfg.Edge.Label":{__eq__:[4,2,1,""],__hash__:[4,2,1,""],__init__:[4,2,1,""]},"gtirb.cfg.Edge.Type":{Branch:[4,3,1,""],Call:[4,3,1,""],Fallthrough:[4,3,1,""],Return:[4,3,1,""],Syscall:[4,3,1,""],Sysret:[4,3,1,""]},"gtirb.ir":{IR:[5,1,1,""]},"gtirb.ir.IR":{__init__:[5,2,1,""],byte_blocks:[5,2,1,""],byte_blocks_at:[5,2,1,""],byte_blocks_on:[5,2,1,""],byte_intervals:[5,2,1,""],byte_intervals_at:[5,2,1,""],byte_intervals_on:[5,2,1,""],cfg_nodes:[5,2,1,""],code_blocks:[5,2,1,""],code_blocks_at:[5,2,1,""],code_blocks_on:[5,2,1,""],data_blocks:[5,2,1,""],data_blocks_at:[5,2,1,""],data_blocks_on:[5,2,1,""],deep_eq:[5,2,1,""],load_protobuf:[5,2,1,""],load_protobuf_file:[5,2,1,""],modules_at:[5,2,1,""],modules_on:[5,2,1,""],proxy_blocks:[5,2,1,""],save_protobuf:[5,2,1,""],save_protobuf_file:[5,2,1,""],sections:[5,2,1,""],sections_at:[5,2,1,""],sections_on:[5,2,1,""],symbolic_expressions_at:[5,2,1,""],symbols:[5,2,1,""]},"gtirb.module":{Module:[6,1,1,""]},"gtirb.module.Module":{FileFormat:[6,1,1,""],ISA:[6,1,1,""],__init__:[6,2,1,""],address:[6,2,1,""],byte_blocks:[6,2,1,""],byte_blocks_at:[6,2,1,""],byte_blocks_on:[6,2,1,""],byte_intervals:[6,2,1,""],byte_intervals_at:[6,2,1,""],byte_intervals_on:[6,2,1,""],cfg_nodes:[6,2,1,""],code_blocks:[6,2,1,""],code_blocks_at:[6,2,1,""],code_blocks_on:[6,2,1,""],data_blocks:[6,2,1,""],data_blocks_at:[6,2,1,""],data_blocks_on:[6,2,1,""],deep_eq:[6,2,1,""],ir:[6,2,1,""],sections_at:[6,2,1,""],sections_on:[6,2,1,""],size:[6,2,1,""],symbolic_expressions_at:[6,2,1,""]},"gtirb.module.Module.FileFormat":{COFF:[6,3,1,""],ELF:[6,3,1,""],IdaProDb32:[6,3,1,""],IdaProDb64:[6,3,1,""],MACHO:[6,3,1,""],PE:[6,3,1,""],RAW:[6,3,1,""],Undefined:[6,3,1,""],XCOFF:[6,3,1,""]},"gtirb.module.Module.ISA":{ARM64:[6,3,1,""],ARM:[6,3,1,""],IA32:[6,3,1,""],MIPS32:[6,3,1,""],MIPS64:[6,3,1,""],PPC32:[6,3,1,""],PPC64:[6,3,1,""],Undefined:[6,3,1,""],ValidButUnsupported:[6,3,1,""],X64:[6,3,1,""]},"gtirb.node":{Node:[7,1,1,""]},"gtirb.node.Node":{__init__:[7,2,1,""],deep_eq:[7,2,1,""],from_uuid:[7,2,1,""]},"gtirb.offset":{Offset:[8,1,1,""]},"gtirb.offset.Offset":{__init__:[8,2,1,""]},"gtirb.proto":{AuxData_pb2:[10,0,0,"-"],ByteInterval_pb2:[11,0,0,"-"],CFG_pb2:[12,0,0,"-"],CodeBlock_pb2:[13,0,0,"-"],DataBlock_pb2:[14,0,0,"-"],IR_pb2:[15,0,0,"-"],Module_pb2:[16,0,0,"-"],Offset_pb2:[17,0,0,"-"],ProxyBlock_pb2:[18,0,0,"-"],Section_pb2:[19,0,0,"-"],Symbol_pb2:[20,0,0,"-"],SymbolicExpression_pb2:[21,0,0,"-"]},"gtirb.proto.AuxData_pb2":{AuxData:[10,1,1,""]},"gtirb.proto.AuxData_pb2.AuxData":{DESCRIPTOR:[10,3,1,""],__slots__:[10,3,1,""],data:[10,3,1,""],type_name:[10,3,1,""]},"gtirb.proto.ByteInterval_pb2":{Block:[11,1,1,""],ByteInterval:[11,1,1,""]},"gtirb.proto.ByteInterval_pb2.Block":{DESCRIPTOR:[11,3,1,""],__slots__:[11,3,1,""],code:[11,3,1,""],data:[11,3,1,""],offset:[11,3,1,""]},"gtirb.proto.ByteInterval_pb2.ByteInterval":{DESCRIPTOR:[11,3,1,""],SymbolicExpressionsEntry:[11,1,1,""],__slots__:[11,3,1,""],address:[11,3,1,""],blocks:[11,3,1,""],contents:[11,3,1,""],has_address:[11,3,1,""],size:[11,3,1,""],symbolic_expressions:[11,3,1,""],uuid:[11,3,1,""]},"gtirb.proto.ByteInterval_pb2.ByteInterval.SymbolicExpressionsEntry":{DESCRIPTOR:[11,3,1,""],__slots__:[11,3,1,""],key:[11,3,1,""],value:[11,3,1,""]},"gtirb.proto.CFG_pb2":{CFG:[12,1,1,""],Edge:[12,1,1,""],EdgeLabel:[12,1,1,""]},"gtirb.proto.CFG_pb2.CFG":{DESCRIPTOR:[12,3,1,""],__slots__:[12,3,1,""],edges:[12,3,1,""],vertices:[12,3,1,""]},"gtirb.proto.CFG_pb2.Edge":{DESCRIPTOR:[12,3,1,""],__slots__:[12,3,1,""],label:[12,3,1,""],source_uuid:[12,3,1,""],target_uuid:[12,3,1,""]},"gtirb.proto.CFG_pb2.EdgeLabel":{DESCRIPTOR:[12,3,1,""],__slots__:[12,3,1,""],conditional:[12,3,1,""],direct:[12,3,1,""],type:[12,3,1,""]},"gtirb.proto.CodeBlock_pb2":{CodeBlock:[13,1,1,""]},"gtirb.proto.CodeBlock_pb2.CodeBlock":{DESCRIPTOR:[13,3,1,""],__slots__:[13,3,1,""],decode_mode:[13,3,1,""],size:[13,3,1,""],uuid:[13,3,1,""]},"gtirb.proto.DataBlock_pb2":{DataBlock:[14,1,1,""]},"gtirb.proto.DataBlock_pb2.DataBlock":{DESCRIPTOR:[14,3,1,""],__slots__:[14,3,1,""],size:[14,3,1,""],uuid:[14,3,1,""]},"gtirb.proto.IR_pb2":{IR:[15,1,1,""]},"gtirb.proto.IR_pb2.IR":{AuxDataEntry:[15,1,1,""],DESCRIPTOR:[15,3,1,""],__slots__:[15,3,1,""],aux_data:[15,3,1,""],cfg:[15,3,1,""],modules:[15,3,1,""],uuid:[15,3,1,""],version:[15,3,1,""]},"gtirb.proto.IR_pb2.IR.AuxDataEntry":{DESCRIPTOR:[15,3,1,""],__slots__:[15,3,1,""],key:[15,3,1,""],value:[15,3,1,""]},"gtirb.proto.Module_pb2":{Module:[16,1,1,""]},"gtirb.proto.Module_pb2.Module":{AuxDataEntry:[16,1,1,""],DESCRIPTOR:[16,3,1,""],__slots__:[16,3,1,""],aux_data:[16,3,1,""],binary_path:[16,3,1,""],entry_point:[16,3,1,""],file_format:[16,3,1,""],isa:[16,3,1,""],name:[16,3,1,""],preferred_addr:[16,3,1,""],proxies:[16,3,1,""],rebase_delta:[16,3,1,""],sections:[16,3,1,""],symbols:[16,3,1,""],uuid:[16,3,1,""]},"gtirb.proto.Module_pb2.Module.AuxDataEntry":{DESCRIPTOR:[16,3,1,""],__slots__:[16,3,1,""],key:[16,3,1,""],value:[16,3,1,""]},"gtirb.proto.Offset_pb2":{Offset:[17,1,1,""]},"gtirb.proto.Offset_pb2.Offset":{DESCRIPTOR:[17,3,1,""],__slots__:[17,3,1,""],displacement:[17,3,1,""],element_id:[17,3,1,""]},"gtirb.proto.ProxyBlock_pb2":{ProxyBlock:[18,1,1,""]},"gtirb.proto.ProxyBlock_pb2.ProxyBlock":{DESCRIPTOR:[18,3,1,""],__slots__:[18,3,1,""],uuid:[18,3,1,""]},"gtirb.proto.Section_pb2":{Section:[19,1,1,""]},"gtirb.proto.Section_pb2.Section":{DESCRIPTOR:[19,3,1,""],__slots__:[19,3,1,""],byte_intervals:[19,3,1,""],name:[19,3,1,""],section_flags:[19,3,1,""],uuid:[19,3,1,""]},"gtirb.proto.Symbol_pb2":{Symbol:[20,1,1,""]},"gtirb.proto.Symbol_pb2.Symbol":{DESCRIPTOR:[20,3,1,""],__slots__:[20,3,1,""],at_end:[20,3,1,""],name:[20,3,1,""],referent_uuid:[20,3,1,""],uuid:[20,3,1,""],value:[20,3,1,""]},"gtirb.proto.SymbolicExpression_pb2":{SymAddrAddr:[21,1,1,""],SymAddrConst:[21,1,1,""],SymStackConst:[21,1,1,""],SymbolicExpression:[21,1,1,""]},"gtirb.proto.SymbolicExpression_pb2.SymAddrAddr":{DESCRIPTOR:[21,3,1,""],__slots__:[21,3,1,""],offset:[21,3,1,""],scale:[21,3,1,""],symbol1_uuid:[21,3,1,""],symbol2_uuid:[21,3,1,""]},"gtirb.proto.SymbolicExpression_pb2.SymAddrConst":{DESCRIPTOR:[21,3,1,""],__slots__:[21,3,1,""],offset:[21,3,1,""],symbol_uuid:[21,3,1,""]},"gtirb.proto.SymbolicExpression_pb2.SymStackConst":{DESCRIPTOR:[21,3,1,""],__slots__:[21,3,1,""],offset:[21,3,1,""],symbol_uuid:[21,3,1,""]},"gtirb.proto.SymbolicExpression_pb2.SymbolicExpression":{DESCRIPTOR:[21,3,1,""],__slots__:[21,3,1,""],addr_addr:[21,3,1,""],addr_const:[21,3,1,""],stack_const:[21,3,1,""]},"gtirb.section":{Section:[22,1,1,""]},"gtirb.section.Section":{Flag:[22,1,1,""],__init__:[22,2,1,""],address:[22,2,1,""],byte_blocks:[22,2,1,""],byte_blocks_at:[22,2,1,""],byte_blocks_on:[22,2,1,""],byte_intervals_at:[22,2,1,""],byte_intervals_on:[22,2,1,""],code_blocks:[22,2,1,""],code_blocks_at:[22,2,1,""],code_blocks_on:[22,2,1,""],data_blocks:[22,2,1,""],data_blocks_at:[22,2,1,""],data_blocks_on:[22,2,1,""],deep_eq:[22,2,1,""],module:[22,2,1,""],size:[22,2,1,""],symbolic_expressions_at:[22,2,1,""]},"gtirb.section.Section.Flag":{Executable:[22,3,1,""],Initialized:[22,3,1,""],Loaded:[22,3,1,""],Readable:[22,3,1,""],ThreadLocal:[22,3,1,""],Undefined:[22,3,1,""],Writable:[22,3,1,""]},"gtirb.serialization":{Codec:[23,1,1,""],CodecError:[23,4,1,""],DecodeError:[23,4,1,""],EncodeError:[23,4,1,""],Int64Codec:[23,1,1,""],MappingCodec:[23,1,1,""],OffsetCodec:[23,1,1,""],SequenceCodec:[23,1,1,""],Serialization:[23,1,1,""],SetCodec:[23,1,1,""],StringCodec:[23,1,1,""],SubtypeTree:[23,5,1,""],TupleCodec:[23,1,1,""],TypeNameError:[23,4,1,""],UUIDCodec:[23,1,1,""],Uint64Codec:[23,1,1,""],UnknownCodecError:[23,4,1,""],UnknownData:[23,1,1,""]},"gtirb.serialization.Codec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.Int64Codec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.MappingCodec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.OffsetCodec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.SequenceCodec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.Serialization":{__init__:[23,2,1,""],decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.SetCodec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.StringCodec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.TupleCodec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.TypeNameError":{__init__:[23,2,1,""]},"gtirb.serialization.UUIDCodec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.Uint64Codec":{decode:[23,2,1,""],encode:[23,2,1,""]},"gtirb.serialization.UnknownCodecError":{__init__:[23,2,1,""]},"gtirb.symbol":{Payload:[24,5,1,""],Symbol:[24,1,1,""]},"gtirb.symbol.Symbol":{__init__:[24,2,1,""],deep_eq:[24,2,1,""],module:[24,2,1,""],referent:[24,2,1,""],value:[24,2,1,""]},"gtirb.symbolicexpression":{SymAddrAddr:[25,1,1,""],SymAddrConst:[25,1,1,""],SymStackConst:[25,1,1,""],SymbolicExpression:[25,5,1,""]},"gtirb.symbolicexpression.SymAddrAddr":{__eq__:[25,2,1,""],__hash__:[25,2,1,""],__init__:[25,2,1,""],deep_eq:[25,2,1,""]},"gtirb.symbolicexpression.SymAddrConst":{__eq__:[25,2,1,""],__hash__:[25,2,1,""],__init__:[25,2,1,""],deep_eq:[25,2,1,""]},"gtirb.symbolicexpression.SymStackConst":{__eq__:[25,2,1,""],__hash__:[25,2,1,""],__init__:[25,2,1,""],deep_eq:[25,2,1,""]},"gtirb.util":{DictLike:[26,1,1,""],DictWrapper:[26,1,1,""],ListWrapper:[26,1,1,""],SetWrapper:[26,1,1,""],get_desired_range:[26,6,1,""],nodes_at:[26,6,1,""],nodes_on:[26,6,1,""],symbolic_expressions_at:[26,6,1,""]},"gtirb.util.DictWrapper":{__delitem__:[26,2,1,""],__getitem__:[26,2,1,""],__init__:[26,2,1,""],__iter__:[26,2,1,""],__len__:[26,2,1,""],__setitem__:[26,2,1,""]},"gtirb.util.ListWrapper":{__delitem__:[26,2,1,""],__getitem__:[26,2,1,""],__init__:[26,2,1,""],__len__:[26,2,1,""],__setitem__:[26,2,1,""],append:[26,2,1,""],insert:[26,2,1,""],remove:[26,2,1,""]},"gtirb.util.SetWrapper":{__contains__:[26,2,1,""],__init__:[26,2,1,""],__iter__:[26,2,1,""],__len__:[26,2,1,""],__or__:[26,2,1,""],add:[26,2,1,""],clear:[26,2,1,""],discard:[26,2,1,""]},"gtirb.version":{API_VERSION:[27,5,1,""],PROTOBUF_VERSION:[27,5,1,""]},gtirb:{AuxData:[0,1,1,""],AuxDataContainer:[0,1,1,""],Block:[0,1,1,""],ByteBlock:[0,1,1,""],ByteInterval:[0,1,1,""],CfgNode:[0,1,1,""],CodeBlock:[0,1,1,""],DataBlock:[0,1,1,""],Edge:[0,1,1,""],IR:[0,1,1,""],Module:[0,1,1,""],Node:[0,1,1,""],Offset:[0,1,1,""],ProxyBlock:[0,1,1,""],Section:[0,1,1,""],Serialization:[0,1,1,""],SymAddrAddr:[0,1,1,""],SymAddrConst:[0,1,1,""],SymStackConst:[0,1,1,""],Symbol:[0,1,1,""],auxdata:[1,0,0,"-"],block:[2,0,0,"-"],byteinterval:[3,0,0,"-"],cfg:[4,0,0,"-"],ir:[5,0,0,"-"],module:[6,0,0,"-"],node:[7,0,0,"-"],offset:[8,0,0,"-"],proto:[9,0,0,"-"],section:[22,0,0,"-"],serialization:[23,0,0,"-"],symbol:[24,0,0,"-"],symbolicexpression:[25,0,0,"-"],util:[26,0,0,"-"],version:[27,0,0,"-"]}},objnames:{"0":["py","module","Python module"],"1":["py","class","Python class"],"2":["py","method","Python method"],"3":["py","attribute","Python attribute"],"4":["py","exception","Python exception"],"5":["py","data","Python data"],"6":["py","function","Python function"]},objtypes:{"0":"py:module","1":"py:class","2":"py:method","3":"py:attribute","4":"py:exception","5":"py:data","6":"py:function"},terms:{"byte":[0,1,2,3,5,6,22,23],"case":[0,6,22],"class":[0,1,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26],"default":[0,1,2,3,5,6,7,22,24],"enum":[0,4,6,22],"function":[0,2,4,5,7],"int":[0,2,3,4,5,6,8,22,24,25,27],"new":[0,1,2,3,5,6,7,22,23,24,26],"return":[0,1,2,3,4,5,6,7,8,22,23,24,25,26],"static":[0,5,23],"true":[0,4,24],"while":[0,3],And:5,For:[0,2,7,23],Has:[0,24],Not:[0,3],The:[0,1,2,3,4,5,6,7,8,22,23,24,27],Use:[0,2,3,5,7,22,23,24],Used:[0,1],__contains__:26,__delitem__:26,__eq__:[0,2,3,4,7,22,24,25],__getitem__:26,__hash__:[0,4,25],__init__:[0,1,2,3,4,5,6,7,8,22,23,24,25,26],__iter__:26,__len__:26,__or__:26,__setitem__:26,__slots__:[10,11,12,13,14,15,16,17,18,19,20,21],_messag:[10,11,12,13,14,15,16,17,18,19,20,21],abc:26,absent:26,accur:[23,26],acorn:[0,6],actual:[0,2,3,7,22,24],add:[0,23,26],added:[0,23],addit:[0,1],addr:[0,3,5,6,22,26],addr_addr:21,addr_const:21,address:[0,2,3,5,6,11,22,24,25],after:[0,4],all:[0,1,2,3,4,5,6,7,22,23,24],alloc:[0,22],allow:[0,2],alreadi:[0,5],also:[0,1,3,4,6,23],alter:[0,23],alwai:[0,4],amen:[0,1,5,6],among:[0,6,22],ani:[0,1,2,3,4,6,7,22,23,25,26],anoth:[0,2,3,4],anyth:[0,1],api:27,api_vers:27,appear:[0,2],append:26,arbitrari:23,architectur:[0,6],arg:26,arm64:[0,6],arm:[0,2,6],around:[0,3],associ:[0,1,3,5,6,23],at_end:[0,20,24],attach:[0,1],attempt:27,aux_data:[0,1,5,6,15,16],auxdata:[0,5,6,10,23,28],auxdata_pb2:[0,9],auxdatacontain:[0,1,5,6],auxdataentri:[15,16],auxiliari:[0,1,5,6],base:[0,1,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26],basic:[0,2],becaus:[0,1,5,6],been:[0,6],befor:26,begin:[0,2,3,5,6,22,24],being:[0,2,3,5,7,22,24],belong:[0,2,3,6,22],between:[0,2,4,6,22],binari:[0,2,3,6,22,23],binary_path:[0,6,16],binaryio:[0,5,23],bit:[0,6,23],blob:23,block:[0,3,4,5,6,11,22,24,28],bool:[0,1,2,3,4,5,6,7,22,24,25],branch:[0,4],bss:[0,3,22],built:[0,23],byte_block:[0,5,6,22],byte_blocks_at:[0,3,5,6,22],byte_blocks_on:[0,3,5,6,22],byte_interv:[0,2,5,6,19,22],byte_intervals_at:[0,5,6,22],byte_intervals_on:[0,5,6,22],byteblock:[0,2,3,5,6,8,22],byteinterv:[0,2,5,6,11,22,28],byteinterval_pb2:[0,9],bytesio:23,cach:[0,2,3,7,22,23,24],calcul:[0,6,22],call:[0,1,2,4,7,23],can:[0,1,3,5,7,22,23,26,27],caught:23,cfg:[0,2,5,12,15,28],cfg_node:[0,5,6],cfg_pb2:[0,9],cfgnode:[0,2,4,5,6],chang:[0,3],check:[0,1,2,3,5,6,7,22,23,24],classmethod:[0,7],classvar:[0,1],clear:26,client:[0,1],cmessag:[10,11,12,13,14,15,16,17,18,19,20,21],code:[0,3,5,6,11,22],code_block:[0,5,6,22],code_blocks_at:[0,3,5,6,22],code_blocks_on:[0,3,5,6,22],codeblock:[0,2,3,5,6,7,8,13,22],codeblock_pb2:[0,9],codec:[0,1,23],codecerror:23,coff:[0,6],collect:26,common:[0,6],compat:[0,22],complet:[0,5],comput:[0,6],condit:[0,4,12],consid:[0,1,3,5,6],consist:[0,3,5],constant:[0,25],construct:[0,2,3,7,22,24],constructor:26,contain:[0,4,5,6,8,22,23],content:[2,3,6,11,22,28],contigu:[0,3],control:[0,4,5,6],core:5,correspond:[0,3,4,23],creat:[0,6,22,23,26],current:[0,6],data:[0,1,2,3,5,6,10,11,22,23],data_block:[0,5,6,22],data_blocks_at:[0,3,5,6,22],data_blocks_on:[0,3,5,6,22],databas:[0,6],datablock:[0,2,3,5,6,8,14,22],datablock_pb2:[0,9],decod:[0,1,2,23],decode_mod:[0,2,13],decodeerror:23,deep:[0,1,2,3,5,6,7,22,24],deep_eq:[0,1,2,3,4,5,6,7,22,24,25],deepli:[0,1,5,6],defin:[0,3,22],delta:[0,6],describ:[0,1,8],descript:[0,4],descriptor:[10,11,12,13,14,15,16,17,18,19,20,21],deseri:[0,23],desir:[0,7],despit:[0,2,3,7,22,24],detail:[0,1,4],determin:[0,1,3],dict:[0,1,6,23,26],dictionari:[0,1,5,6,23],dictlik:[0,1,5,6,26],dictwrapp:26,differ:[0,2,3,6,7,22,24],differenti:[0,2],direct:[0,4,12],directli:[0,2,22],discard:26,disk:[0,1],displac:[0,8,17,23],doe:[0,2,4,6,22],due:[0,4],dure:23,edg:[0,2,4,5,12],edgelabel:12,effect:26,either:[0,3,5,6,22,23],element:26,element_id:[0,8,17],elf:[0,6],empti:[0,1,5,6],encapsul:[0,23],encod:[0,1,5,23],encodeerror:23,encount:23,end:[0,24,26],endpoint:[0,2],enhanc:[0,6],entri:23,entry_point:[0,6,16],equal:[0,1,2,3,5,6,7,22,24],equival:[0,4],etc:[0,22],everi:[0,3,5,6,22],exact:[0,2,3,7,22,24],exampl:[0,1,2,3,7,23],except:[23,26],exclus:[0,24],execut:[0,4,6,22],exist:[0,4,6,7],explicit:[0,4],express:[0,3,5,6,22,25],extend:[0,6],extens:[0,6],factor:[0,25],fallthrough:[0,4],fals:[0,4,24],field:[0,1,3,10,11,12,13,14,15,16,17,18,19,20,21],file:[0,3,5,6,22,23],file_format:[0,6,16],file_nam:[0,5],fileformat:[0,6],filenam:5,find:[0,3,5,6,22],first:[23,26],fix:[0,3,6,22],flag:[0,22],flow:[0,4,5,6],follow:23,form:[0,25],format:[0,1,3,6],formerli:[0,6],forwardref:[0,2,3,5,6,22,23,24],free:[0,3],from:[0,1,2,3,4,5,6,7,22,23,25,27],from_uuid:[0,7],gener:[0,1,2,3,4,5,6,7,22,23,24,26],get:[0,2,6,7,22],get_desired_rang:26,give:23,given:[0,6],googl:[10,11,12,13,14,15,16,17,18,19,20,21],graph:[0,5],greater:[0,3],group:[0,3],guarante:[0,6],handl:23,has:[0,2,6,22],has_address:11,hash:[0,4,25],have:[0,2,3,4,5,6,7,22,24],help:[23,26],high:[0,3],highest:[0,6,22],hint:[23,24,25],hit:23,hold:[0,1],i386:[0,6],ia32:[0,6],ibm:[0,6],ida:[0,6],idaprodb32:[0,6],idaprodb64:[0,6],identifi:[0,6],imagebytemap:[0,22],immedi:[0,4],implement:23,implment:[0,2,3,7,22,24],incoming_edg:[0,2],independ:[0,1],index:[26,28],indic:[0,3,4],indicitav:[0,6],indirect:[0,2,4],individu:[0,1],inform:[0,4,5],initi:[0,1,3,5,6,22,23,26],initialized_s:[0,3],insert:26,insid:[0,8],instanc:[0,1,5,23],instead:[0,1,5,6],instruct:[0,2,4,6],instructon:[0,4],int64codec:23,integ:[0,23,24],integr:[0,24],intel:[0,6],interest:[0,8],interlock:[0,6],intern:[0,5],interv:[0,2,3,5,6,22],invok:23,ir_pb2:[0,9],isa:[0,2,6,16],item:23,iter:[0,2,3,5,6,22,23,26],its:[0,24],itself:[0,3],jump:[0,2,4],kei:[0,1,5,6,11,15,16,26],kept:[0,2,22],known:[0,2,6,22],label:[0,4,12],languag:[0,1],length:[0,2],level:23,librari:[0,6],link:[0,6],linkabl:[0,6],list:[0,1,5,23],listwrapp:26,load:[0,5,6,22,23,27],load_protobuf:[0,5,23],load_protobuf_fil:[0,5],loadabl:[0,6],loadtim:[0,3],locat:[0,3,4,8],look:[0,7],lowest:[0,6,22],mach:[0,6],machin:[0,6],macho:[0,6],mai:[0,1,2,3,4,7,22,24],malform:23,manag:[0,23],manner:[0,1],manual:[0,2,3,7,22,24],map:[0,1,3,5,6,23,24,26],mappingcodec:23,mean:[0,24],memori:[0,3,4,6,22],messag:[0,5,10,11,12,13,14,15,16,17,18,19,20,21],messagedescriptor:[10,11,12,13,14,15,16,17,18,19,20,21],met:[0,4],method:[0,2,3,7,22,23,24],microprocessor:[0,6],microsoft:[0,6],mips32:[0,6],mips64:[0,6],mode:[0,2],modul:28,module_pb2:[0,9],modules_at:[0,5],modules_on:[0,5],more:[0,4,6,22],move:[0,3],multipl:[0,2,5],must:[0,3,4],mutablemap:26,mutablesequ:26,mutableset:26,mutual:[0,24],my_custom_typ:[0,23],mycustomcodec:[0,23],name:[0,1,5,6,16,19,20,22,23,24],necessarili:[0,1,5,6],need:[0,1,2,3,5,6,7,22,23,24],neither:[0,2],node:[0,1,2,3,4,5,6,8,22,23,24,26,28],nodes_at:26,nodes_on:26,non:[0,4],none:[0,1,2,3,4,5,6,7,8,22,23,24,25],nor:[0,2],note:[0,6,22],number:[0,3,4],object:[0,1,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25],occur:[0,3,4],occurr:26,offset:[0,2,3,5,6,11,17,21,22,23,25,28],offset_pb2:[0,9],offsetcodec:23,often:[0,3],old:27,omit:[0,4],onc:[0,22],one:[0,3,6,22],onli:[0,2,3,7,22,23,24],open:5,oper:[0,3],optim:[0,6],option:[0,1,2,3,4,5,6,7,22,23,24],order:[0,1,3],origin:[0,2,3],other:[0,1,2,3,4,5,6,7,22,23,24,25,26],otherwis:[0,4],out:[0,23],outgo:[0,4],outgoing_edg:[0,2],output:[0,7],overlap:[0,3,5,6,22],overrid:[0,1,5,6],overridden:[0,23],packag:28,page:28,paramet:[0,1,2,3,4,5,6,7,8,22,23,24,25],parameter:[0,1],pars:[0,5,23],part:[0,4],pass:26,past:[0,3],path:[0,4,5,6],payload:[0,24],per:[0,22],perform:[0,6],physic:[0,3],pipelin:[0,6],placehold:[0,2],point:[0,2,8,24],pointer:[0,2,3,7,22,24],portabl:[0,1,6],possibl:[0,2,4,24],powerpc:[0,6],ppc32:[0,6],ppc64:[0,6],preced:[0,4],prefer:[0,6],preferred_addr:[0,6,16],present:[0,2,3,6,22,26],preserv:[0,3],pro:[0,6],program:[0,3],proper:[0,1],properti:[0,2,3,5,6,22,24],proto:[0,28],protobuf:[0,5,10,11,12,13,14,15,16,17,18,19,20,21,22,27],protobuf_fil:[0,5],protobuf_vers:27,proxi:[0,6,16],proxy_block:[0,5],proxyblock:[0,2,4,5,6,18],proxyblock_pb2:[0,9],purpos:[0,6],pyext:[10,11,12,13,14,15,16,17,18,19,20,21],python:[0,5,23],rais:[0,7,26,27],rang:[0,3,5,6,22,26],rather:[0,3,24],raw:[0,6,23],raw_byt:[0,23],read:[0,5,22,23,27],readabl:[0,22],rebas:[0,6],rebase_delta:[0,6,16],refer:[0,2,3,4,6,7,22,24],referenc:[0,7],referent_uuid:20,region:[0,3],regist:[0,23],rel:[0,3],remov:26,repres:[0,1,2,4,5,6,22,23,24,25],represent:[0,5],request:[0,7],requir:[0,1],resolut:[0,6],rich:[0,1],risc:[0,6],runtim:[0,22],safe:[0,3],same:[0,2,3,5,6,7,22,24],save:[0,3,5,23],save_protobuf:[0,5,23],save_protobuf_fil:[0,5],scale:[0,21,25],search:28,section:[0,3,5,6,16,19,28],section_flag:19,section_pb2:[0,9],sections_at:[0,5,6],sections_on:[0,5,6],see:[0,1,23,26],self:[0,1,2,3,4,5,6,7,22,23,24,25,26],semant:[0,3,27],sequenc:[0,4,23,26],sequencecodec:23,seri:[0,1],serial:[0,1,28],serv:[0,2],set:[0,1,3,4,5,6,23],setcodec:23,setwrapp:26,share:[0,2,3,7,22,24],should:[0,2,3,7,22,24],sign:23,signatur:[23,26],singl:[0,3,5,6,22],site:[0,4],size:[0,2,3,6,11,13,14,22],slow:26,smaller:[0,3],some:[0,2,6],sourc:[0,1,2,3,4,5,6,7,8,22,23,24,25,26],source_uuid:12,specif:[0,1,6,7,22],specifi:[0,5,6,7,23],stack:[0,25],stack_const:21,stage:[0,6],start:[0,2],store:[0,1,2,3,5,6,22],str:[0,1,5,6,23,27],stream:[0,5,23],string:[0,1,6,23],stringcodec:23,structur:[0,2,3,7,22,24],sub:[0,2],subclass:[0,2,7,23],submodul:28,submoudl:26,subpackag:28,subtract:[0,25],subtyp:23,subtypetre:23,suffici:[0,2,3,7,22,24],sym1:[0,25],sym2:[0,25],sym:[0,25],symaddraddr:[0,3,5,6,21,22,25],symaddrconst:[0,3,5,6,21,22,25],symbol1:[0,25],symbol1_uuid:21,symbol2:[0,25],symbol2_uuid:21,symbol:[0,2,3,4,5,6,16,20,22,25,28],symbol_pb2:[0,9],symbol_uuid:21,symbolic_express:[0,3,11],symbolic_expressions_at:[0,3,5,6,22,26],symbolicexpress:[0,3,5,6,21,22,28],symbolicexpression_pb2:[0,9],symbolicexpressionsentri:11,symexpr:[0,3,5,6,22],symstackconst:[0,3,5,6,21,22,25],syscal:[0,4],sysret:[0,4],system:[0,4],tabl:[0,1],taken:[0,3,4],target:[0,2,4,6],target_uuid:12,text:[0,22],than:[0,3,24],thei:[0,1,5,6],them:[0,4],thi:[0,1,2,3,4,5,6,7,22,23,24,26,27],thread:[0,22],threadloc:[0,22],thumb:[0,2],top:23,transfer:[0,4],truncat:[0,3],tupl:[0,3,5,6,22,23,26],tuplecodec:23,two:[0,2,3,4,7,22,23,24],type:[0,1,2,3,4,5,6,7,8,12,22,23,24,25,26],type_nam:[0,1,10,23],typeerror:[0,7],typenameerror:23,typic:[0,2,3,7,22,24],uint64codec:23,uncomput:[0,4],uncondit:[0,4],undefin:[0,6,22],underli:[0,3],uniniti:[0,3],union:[0,3,5,6,22,24,25],uniti:[0,3,6],unknown:[0,3,4,6,23],unknowncodecerror:23,unknowndata:23,unless:[0,4],unsign:23,usabl:26,use:[0,5,6,22],used:[0,1,2,3,7,22,23,24],using:[0,23],util:[0,1,5,6,28],uuid4:[0,1,2,3,5,6,7,22,24],uuid:[0,1,2,3,5,6,7,8,11,13,14,15,16,18,19,20,22,23,24],uuidcodec:23,val:[0,23],valid:[0,1,4,23],validbutunsupport:[0,6],valu:[0,1,3,4,5,6,11,15,16,20,22,23,24,25,26],valueerror:[26,27],variabl:[0,1,2,3,4,5,6,7,8,22,23,24,25],vector:[0,3],version:[0,5,15,28],vertic:[0,2,12],via:[0,1,2,3,4,5,6,7,22,23,24],wai:[0,1],want:[0,5],what:[0,6],when:[0,2,3,4,5,7,22,23,24],where:[0,3,6],which:[0,2,3,5,7,22,23,24],whose:[0,2],without:[0,4,6],would:[0,2],writabl:[0,22],write:[0,5,23,27],written:[0,2,22],x32:[0,6],x64:[0,6],x86:[0,6],x86_64:[0,6],xcoff:[0,6],yet:[0,6],yield:[0,3,5,6,22,26],you:[0,2,3,5,7,22,23,24],zero:[0,3]},titles:["gtirb package","gtirb.auxdata module","gtirb.block module","gtirb.byteinterval module","gtirb.cfg module","gtirb.ir module","gtirb.module module","gtirb.node module","gtirb.offset module","gtirb.proto package","gtirb.proto.AuxData_pb2 module","gtirb.proto.ByteInterval_pb2 module","gtirb.proto.CFG_pb2 module","gtirb.proto.CodeBlock_pb2 module","gtirb.proto.DataBlock_pb2 module","gtirb.proto.IR_pb2 module","gtirb.proto.Module_pb2 module","gtirb.proto.Offset_pb2 module","gtirb.proto.ProxyBlock_pb2 module","gtirb.proto.Section_pb2 module","gtirb.proto.Symbol_pb2 module","gtirb.proto.SymbolicExpression_pb2 module","gtirb.section module","gtirb.serialization module","gtirb.symbol module","gtirb.symbolicexpression module","gtirb.util module","gtirb.version module","Welcome to gtirb\u2019s documentation!"],titleterms:{auxdata:1,auxdata_pb2:10,block:2,byteinterv:3,byteinterval_pb2:11,cfg:4,cfg_pb2:12,codeblock_pb2:13,content:[0,9],datablock_pb2:14,document:28,gtirb:[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28],indic:28,ir_pb2:15,modul:[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27],module_pb2:16,node:7,offset:8,offset_pb2:17,packag:[0,9],proto:[9,10,11,12,13,14,15,16,17,18,19,20,21],proxyblock_pb2:18,section:22,section_pb2:19,serial:23,submodul:[0,9],subpackag:0,symbol:24,symbol_pb2:20,symbolicexpress:25,symbolicexpression_pb2:21,tabl:28,util:26,version:27,welcom:28}})