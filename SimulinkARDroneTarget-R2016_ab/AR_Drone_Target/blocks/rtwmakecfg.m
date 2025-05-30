function makeInfo = rtwmakecfg()
%RTWMAKECFG adds include and source directories to the make files.
%    makeInfo=rtwmakecfg returns a structured array containing build info.
%    Please refer to the rtwmakecfg API section in the Simulink Coder
%    documentation for details on the format of this structure.
%    Simulink version    : 8.8 (R2016b) 25-Aug-2016
%    MATLAB file generated on : 27-Apr-2022 17:44:31

% Verify the Simulink version
verify_simulink_version();

% Get the current directory
currDir = pwd;

% Get the MATLAB search path, remove the toolbox sub-directories except LCT demos
matlabPath = legacycode.lct.util.getSearchPath();

% Declare cell arrays for storing the paths
allIncPaths = {};
allSrcPaths = {};

% Get the build type
isSimTarget = is_simulation_target();
% Get the serialized paths information
info = get_serialized_info();

% Get all S-Function's name in the current model
sfunNames = {};
if ~isempty(bdroot)
    sfunBlks = find_system(bdroot,...
        'LookUnderMasks', 'all',...
        'FollowLinks', 'on',...
        'BlockType', 'S-Function'...
    );
    sfunNames = get_param(sfunBlks, 'FunctionName');
end

for ii = 1:numel(info)
    sfunInfo = info(ii);
    % If the S-Function isn't part of the current build then skip its path info
    if ~any(strcmp(sfunInfo.SFunctionName, sfunNames))
        continue
    end

    % Call the helper
    pathInfo = legacycode.lct.util.resolvePaths(sfunInfo, isSimTarget==1, currDir, matlabPath);

    % Concatenate known include and source directories
    allIncPaths = RTW.uniquePath([allIncPaths pathInfo.IncPaths(:)']);
    allSrcPaths = RTW.uniquePath([allSrcPaths pathInfo.SrcPaths(:)']);
end

% Additional include directories
makeInfo.includePath = correct_path_name(allIncPaths);

% Additional source directories
makeInfo.sourcePath = correct_path_name(allSrcPaths);

%% ------------------------------------------------------------------------
function info = get_serialized_info()

% Allocate the output structure array
info(1:8) = struct(...
    'SFunctionName', '',...
    'IncPaths', {{}},...
    'SrcPaths', {{}},...
    'LibPaths', {{}},...
    'SourceFiles', {{}},...
    'HostLibFiles', {{}},...
    'TargetLibFiles', {{}},...
    'singleCPPMexFile', false,...
    'Language', ''...
    );

info(1).SFunctionName = 'print';
info(1).SrcPaths = {'.'};
info(1).SourceFiles = {'ARprintf.c'};
info(1).Language = 'C';

info(2).SFunctionName = 'Init_Actuator';
info(2).SrcPaths = {'.'};
info(2).SourceFiles = {'act_init.c', 'Actuators.c', 'GPIO.c'};
info(2).Language = 'C';

info(3).SFunctionName = 'IMU_Sfcn_mex';
info(3).SrcPaths = {'.'};
info(3).SourceFiles = {'IMU_Navdata.c', 'IMU_Navdata_wrapper.c'};
info(3).Language = 'C';

info(4).SFunctionName = 'ARDrone_LED';
info(4).SrcPaths = {'.'};
info(4).SourceFiles = {'led.c', 'Actuators.c', 'GPIO.c'};
info(4).Language = 'C';

info(5).SFunctionName = 'ARDrone_Motor';
info(5).SourceFiles = {'motor.c', 'Actuators.c', 'GPIO.c'};
info(5).Language = 'C';

info(6).SFunctionName = 'Version_Check';
info(6).SrcPaths = {'.'};
info(6).SourceFiles = {'versionCheck.c'};
info(6).Language = 'C';

info(7).SFunctionName = 'Battery_Sfcn_mex';
info(7).SrcPaths = {'.'};
info(7).SourceFiles = {'BatteryMeasure.c', 'BatteryMeasure_Wrapper.c'};
info(7).Language = 'C';

info(8).SFunctionName = 'UDP_Recv_Sfcn';
info(8).SrcPaths = {'.'};
info(8).SourceFiles = {'udp_recv.c'};
info(8).Language = 'C';

%% ------------------------------------------------------------------------
function verify_simulink_version()

% Retrieve Simulink version
slVer = ver('simulink');
factor = 1.0;
thisVer = 0.0;
for ii = 1:numel(slVer.Version)
    if slVer.Version(ii)=='.'
        factor = factor/10.0;
    else
        thisVer = thisVer + sscanf(slVer.Version(ii), '%d')*factor;
    end
end

% Verify that the actual platform supports the function used
if thisVer < 8.7
    DAStudio.error('Simulink:tools:LCTErrorBadSimulinkVersion', sprintf('%g',thisVer))
end

%% ------------------------------------------------------------------------
function pathSet = correct_path_name(pathSet)

for ii = 1:numel(pathSet)
    pathSet{ii} = rtw_alt_pathname(pathSet{ii});
end
pathSet = RTW.uniquePath(pathSet);

%% ------------------------------------------------------------------------
function isSimTarget = is_simulation_target()

% Default output value
isSimTarget = 0;

% Get the current model and the code generation type to decide
% if we must link with the host libraries or with the target libraries
try
    modelName = get_param(0, 'CurrentSystem');
    if ~isempty(modelName)
        modelName = bdroot(modelName);
        sysTarget = get_param(modelName, 'RTWSystemTargetFile');
        isSimTarget = ~isempty([strfind(sysTarget, 'rtwsfcn') strfind(sysTarget, 'accel')]);

        mdlRefSimTarget = get_param(modelName,'ModelReferenceTargetType');
        isSimTarget = strcmpi(mdlRefSimTarget, 'SIM') || isSimTarget;

        % Verify again it's not Accelerator
        if ~isSimTarget
            simMode = get_param(modelName, 'SimulationMode');
            simStat = get_param(modelName, 'SimulationStatus');
            isSimTarget = strcmp(simStat, 'initializing') & strcmp(simMode, 'accelerator');
        end
    end
catch
end
