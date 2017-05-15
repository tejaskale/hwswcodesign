set proj_name tresor_fsm
set proj_dir [file normalize [file dirname [info script]]/$proj_name]
set thepart "xc7z020clg484-1"

create_project $proj_name  $proj_dir -part $thepart
set_property "board_part" "em.avnet.com:zed:part0:1.0" [current_project]
set_property "target_language" "VHDL" [current_project]
add_files -norecurse -force $proj_dir/../tresor_fsm.vhd
add_files -fileset sim_1 -norecurse -force $proj_dir/../tresor_fsm_tb.vhd
update_compile_order -fileset sources_1
update_compile_order -fileset sim_1

set obj [get_filesets sim_1]
set_property "runtime" "10 us" $obj

puts "INFO: Project created: $proj_name"
