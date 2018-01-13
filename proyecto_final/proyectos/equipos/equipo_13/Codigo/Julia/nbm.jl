using LightGraphs
using ArgParse

include("utils.jl")

parser = ArgParseSettings(description = "Crear matriz de Hashimoto.")

@add_arg_table parser begin
    "--output","-o"
    "file"
end

args = parse_args(parser)

output_file = get(args, "output", STDOUT)
if is(output_file, nothing)
    output_file = STDOUT
else
    output_file = args["output"]
end

function debug(msg)
    write(STDERR, msg)
end

debug("Output File: $(output_file)\n")

g = loadgraph(args["file"],:gml)

NBM, edgeidmap = nbm_matrix(g)

println(full(NBM))
