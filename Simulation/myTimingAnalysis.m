function varargout = myTimingAnalysis(varargin)
% MYTIMINGANALYSIS M-file for myTimingAnalysis.fig
%      MYTIMINGANALYSIS, by itself, creates a new MYTIMINGANALYSIS or raises the existing
%      singleton*.
%
%      H = MYTIMINGANALYSIS returns the handle to a new MYTIMINGANALYSIS or the handle to
%      the existing singleton*.
%
%      MYTIMINGANALYSIS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MYTIMINGANALYSIS.M with the given input arguments.
%
%      MYTIMINGANALYSIS('Property','Value',...) creates a new MYTIMINGANALYSIS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before myTimingAnalysis_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to myTimingAnalysis_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% Last Modified by GUIDE v2.5 10-Jun-2011 15:31:29

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @myTimingAnalysis_OpeningFcn, ...
                   'gui_OutputFcn',  @myTimingAnalysis_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before myTimingAnalysis is made visible.
function myTimingAnalysis_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to myTimingAnalysis (see VARARGIN)

% Choose default command line output for myTimingAnalysis
handles.output = hObject;

handles.dataPath       = cell(12,7);
handles.dataPath(:,4)  = {0};
handles.dataPath(:,5)  = {0};

handles.clockPath      = cell(12,7);
handles.clockPath(:,4)  = {0};
handles.clockPath(:,5)  = {0};

handles.clkFreq   = 10;
handles.delay     = 0.7;
handles.delayVar  = 4.0;
handles.dataSlew  = 5.0;
handles.clockSlew = 0;

set(handles.edit1,'String',num2str(handles.clkFreq));
set(handles.edit2,'String',num2str(handles.delayVar));
set(handles.edit3,'String',num2str(handles.delay));
set(handles.edit5,'String',num2str(handles.dataSlew));
set(handles.edit4,'String',num2str(handles.clockSlew));
set(handles.uitable2,'Data',handles.dataPath);
set(handles.uitable3,'Data',handles.clockPath);

xlabel('Time (ns)')

% Update handles structure
guidata(hObject, handles);


% --- Outputs from this function are returned to the command line.
function varargout = myTimingAnalysis_OutputFcn(hObject, eventdata, handles) 
varargout{1} = handles.output;



function edit1_Callback(hObject, eventdata, handles)
handles.clkFreq = str2double(get(hObject,'string'));
guidata(hObject,handles)


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


function edit2_Callback(hObject, eventdata, handles)
handles.delayVar = str2double(get(hObject,'string'));
guidata(hObject,handles)


% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit3_Callback(hObject, eventdata, handles)
handles.delay = str2double(get(hObject,'string'));
guidata(hObject,handles)


% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function edit4_Callback(hObject, eventdata, handles)
handles.clockSlew = str2double(get(hObject,'string'));
guidata(hObject,handles)


% --- Executes during object creation, after setting all properties.
function edit4_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function edit5_Callback(hObject, eventdata, handles)
handles.dataSlew = str2double(get(hObject,'string'));
guidata(hObject,handles)


% --- Executes during object creation, after setting all properties.
function edit5_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes when entered data in editable cell(s) in uitable2.
function uitable2_CellEditCallback(hObject, eventdata, handles)
indexR = eventdata.Indices(1);
indexC = eventdata.Indices(2);
if indexC == 3
    if isnan(str2double(eventdata.EditData)) == 0
        handles.dataPath(indexR,indexC) = {str2double(eventdata.EditData)};
        handles.dataPath(indexR,4) = {handles.dataPath{indexR,indexC}*handles.delay*(1-handles.delayVar/100)};
        handles.dataPath(indexR,5) = {handles.dataPath{indexR,indexC}*handles.delay*(1+handles.delayVar/100)};
        set(hObject,'Data',handles.dataPath);
    else
        handles.dataPath(indexR,indexC) = {eventdata.EditData};
        set(hObject,'Data',handles.dataPath);
    end
elseif indexC > 2 && indexC < 6
    handles.dataPath(indexR,indexC) = {str2double(eventdata.EditData)};
else
    handles.dataPath(indexR,indexC) = {eventdata.EditData};
    set(hObject,'Data',handles.dataPath);
end
guidata(hObject, handles);


% --- Executes when entered data in editable cell(s) in uitable3.
function uitable3_CellEditCallback(hObject, eventdata, handles)
indexR = eventdata.Indices(1);
indexC = eventdata.Indices(2);
if indexC == 3
    if isnan(str2double(eventdata.EditData)) == 0
        handles.clockPath(indexR,indexC) = {str2double(eventdata.EditData)};
        handles.clockPath(indexR,4) = {handles.clockPath{indexR,indexC}*handles.delay*(1-handles.delayVar/100)};
        handles.clockPath(indexR,5) = {handles.clockPath{indexR,indexC}*handles.delay*(1+handles.delayVar/100)};
        set(hObject,'Data',handles.clockPath);
    else
        handles.clockPath(indexR,indexC) = {0};
    end
elseif indexC > 2 && indexC < 6
    handles.clockPath(indexR,indexC) = {str2double(eventdata.EditData)};
else
    handles.clockPath(indexR,indexC) = {eventdata.EditData};
    set(hObject,'Data',handles.clockPath);
end
guidata(hObject, handles);


% --- Executes when selected cell(s) is changed in uitable2.
function uitable2_CellSelectionCallback(hObject, eventdata, handles)


% --- Executes when selected cell(s) is changed in uitable3.
function uitable3_CellSelectionCallback(hObject, eventdata, handles)


function pushbutton1_Callback(hObject, eventdata, handles)
minDataDelay  = 0;
maxDataDelay  = 0;
minClockDelay = 0;
maxClockDelay = 0;
clockSlew     = handles.clockSlew;
dataSlew      = handles.dataSlew;

for ii = 1:12
    minDataDelay  = minDataDelay  + handles.dataPath{ii,4};
    maxDataDelay  = maxDataDelay  + handles.dataPath{ii,5};
    minClockDelay = minClockDelay + handles.clockPath{ii,4};
    maxClockDelay = maxClockDelay + handles.clockPath{ii,5};
end

Ts = 1/(handles.clkFreq*1e6)*1e9;               % Period in ns
tHold = minDataDelay - maxClockDelay;
tSetup = Ts + minClockDelay - maxDataDelay;
clock = [1 1 0 0 1 1 0 0 1 1];
tClk  = [0-Ts/1.25 0-Ts/2 0-Ts/2 0 0 Ts/2 Ts/2 Ts Ts Ts*1.25];
tData = tHold:.001:Ts - tSetup;

X1_tmax  = tData(1) + dataSlew;
X1_tData = tData(1):.001:X1_tmax;
X1       = (X1_tData - tHold)*(1/dataSlew);
X2_tData = X1_tData + tData(end);

plot(tClk,clock)
hold on
plot(X1_tData,X1+1.2,'r')
plot(X1_tData,flipdim(X1,2)+1.2,'r')
plot(X1_tData+Ts,X1+1.2,'r')
plot(X1_tData+Ts,flipdim(X1,2)+1.2,'r')
plot(X1_tData-Ts,X1+1.2,'r')
plot(X1_tData-Ts,flipdim(X1,2)+1.2,'r')

plot(X2_tData,X1+1.2,'r')
plot(X2_tData,flipdim(X1,2)+1.2,'r')
plot(X2_tData+Ts,X1+1.2,'r')
plot(X2_tData+Ts,flipdim(X1,2)+1.2,'r')
plot(X2_tData-Ts,X1+1.2,'r')
plot(X2_tData-Ts,flipdim(X1,2)+1.2,'r')

plot([min(tClk) max(tClk)], [1.2 1.2],'r');
plot([min(tClk) max(tClk)], [2.2 2.2],'r');
axis([min(tClk) max(tClk) -.1 2.3])
xlabel('Time (ns)')
%set(handles.axes,'YTickLabel',{},'YTick',zeros(1,0));
hold off



